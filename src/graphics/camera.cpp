#include <hexvel-graphics/graphics/camera.hpp>

#include "../linalg/linalg.hpp"

#include <cmath>

Camera::Camera() :
    m_worldUp(0.f, 1.f, 0.f),
    m_yaw(0.f),
    m_pitch(0.f),
    m_position(0.f, 0.f, 0.f),
    m_viewNeedUpdate(true),
    m_projNeedUpdate(true)
{}

void Camera::lookAt(float yaw, float pitch) {
    m_yaw = yaw;
    m_pitch = pitch;
    m_viewNeedUpdate = true;
}

void Camera::rotate(float dYaw, float dPitch) {
    m_yaw += dYaw;
    m_pitch += dPitch;
    m_viewNeedUpdate = true;
}

void Camera::setWorldUp(Vec3f worldUp) {
    m_worldUp = worldUp;
    m_viewNeedUpdate = true;
}

void Camera::setPosition(Vec3f position) {
    m_position = position;
    m_viewNeedUpdate = true;
}

void Camera::move(Vec3f shift) {
    m_position += shift;
    m_viewNeedUpdate = true;
}

const Transform& Camera::getViewTransform() const {
    if (m_viewNeedUpdate) {
        constexpr float DEG2RAD = 3.141592654f / 180;

        Vec3f front;
        front.x = cos(DEG2RAD * m_yaw  ) * cos(DEG2RAD * m_pitch);
        front.y = sin(DEG2RAD * m_pitch);
        front.z = sin(DEG2RAD * m_yaw  ) * cos(DEG2RAD * m_pitch);

        Vec3f right = normalize(cross(front, m_worldUp));
        Vec3f up = normalize(cross(right, front));

        Vec3f f = normalize(front);
        Vec3f s = normalize(cross(front, up));
        Vec3f u = normalize(cross(s, front));

        float s_p = -dot(s, m_position);
        float u_p = -dot(u, m_position);
        float f_p =  dot(f, m_position);

        // Look at transform
        m_viewTransform = Transform(
            s.x, u.x, -f.x, 0.f,
            s.y, u.y, -f.y, 0.f,
            s.z, u.z, -f.z, 0.f,
            s_p, u_p,  f_p, 1.f
        );

        m_viewNeedUpdate = false;
    }

    return m_viewTransform;
}

const Transform& Camera::getProjTransform() const {
    if (m_projNeedUpdate) {
        float fovy = 45.f;
        float aspect = 1.f;
        float near = 0.1f;
        float far = 10.f;

        float tanHalfFovy = tanf(fovy / 2.f);
        
        float m[4][4] = {0};
        m[0][0] = 1.f / (aspect * tanHalfFovy);
        m[1][1] = 1.f / (tanHalfFovy);
        m[2][2] = -(far + near) / (far - near);
        m[3][3] = 1.f;
        m[2][3] = -1.f;
        m[3][2] = -(2.f * far * near) / (far - near);

        m_projTransform = Transform(&m[0][0]);

        m_projNeedUpdate = false;
    }

    return m_projTransform;
}