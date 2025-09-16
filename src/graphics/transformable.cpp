#include <gcore/graphics/transformable.hpp>

#include "../linalg/linalg.hpp"

#include <cmath>

Transformable::Transformable() :
    m_position(0.f, 0.f, 0.f),
    m_scaleFactors(1.f, 1.f, 1.f),
    m_rotationMatrix(Transform::Identity),
    m_transformNeedUpdate(false),
    m_inverseTransformNeedUpdate(false)
{ }

void Transformable::setPosition(float x, float y, float z) {
    this->setPosition(Vec3f(x, y, z));
}

void Transformable::setPosition(const Vec3f& position) {
    m_position = position;
    m_transformNeedUpdate = true;
    m_inverseTransformNeedUpdate = true;
}

void Transformable::setRotation(float angle, Vec3f axis) {
    Vec3f u = normalize(axis);

    float u_x2 = u.x * u.x;
    float u_y2 = u.y * u.y;
    float u_z2 = u.z * u.z;
    float u_xy = u.x * u.y;
    float u_xz = u.x * u.z;
    float u_yz = u.y * u.z;
    float sina = sin(angle);
    float cosa = cos(angle);
    float _1_c = 1.f - cosa;
    
    m_rotationMatrix = Transform(
        u_x2*_1_c +     cosa, u_xy*_1_c - u.z*sina, u_xz*_1_c + u.y*sina, 0.f,
        u_xy*_1_c + u.z*sina, u_y2*_1_c +     cosa, u_yz*_1_c - u.x*sina, 0.f,
        u_xz*_1_c - u.y*sina, u_yz*_1_c + u.x*sina, u_z2*_1_c +     cosa, 0.f,
                         0.f,                  0.f,                  0.f, 1.f
    );

    m_transformNeedUpdate = true;
    m_inverseTransformNeedUpdate = true;
}

void Transformable::setScale(float xFactor, float yFactor, float zFactor) {
    this->setScale(Vec3f(xFactor, yFactor, zFactor));
}

void Transformable::setScale(const Vec3f& factors) {
    m_scaleFactors = factors;
    m_transformNeedUpdate = true;
    m_inverseTransformNeedUpdate = true;
}

const Vec3f& Transformable::getPosition() const {
    return m_position;
}

const float* Transformable::getRotation() const {
    return m_rotationMatrix.getMatrix();
}

const Vec3f& Transformable::getScale() const {
    return m_scaleFactors;
}

void Transformable::move(float xOffset, float yOffset, float zOffset) {
   this->move(Vec3f(xOffset, yOffset, zOffset));
}

void Transformable::move(const Vec3f& offset) {
    this->setPosition(m_position + offset);
}

// void Transformable::rotate(float angle, Vec3f axis)
// {
//     Vec3f u = normalize(axis);

//     float u_x2 = u.x * u.x;
//     float u_y2 = u.y * u.y;
//     float u_z2 = u.z * u.z;
//     float u_xy = u.x * u.y;
//     float u_xz = u.x * u.z;
//     float u_yz = u.y * u.z;
//     float _1_c = 1 - cos(angle);
//     float sina = sin(angle);
//     float cosa = cos(angle);

//     Transform m = Transform(
//         u_x2*_1_c +     cosa, u_xy*_1_c - u.z*sina, u_xz*_1_c + u.y*sina, 0.f,
//         u_xy*_1_c + u.z*sina, u_y2*_1_c +     cosa, u_yz*_1_c - u.x*sina, 0.f,
//         u_xz*_1_c - u.y*sina, u_yz*_1_c + u.x*sina, u_z2*_1_c +     cosa, 0.f,
//                          0.f,                  0.f,                  0.f, 1.f
//     );

//     m_rotationMatrix.combine(m);
    
//     this->_transformNeedUpdate = true;
//     this->_inverseTransformNeedUpdate = true;
// }

void Transformable::scale(float xFactor, float yFactor, float zFactor) {
    this->scale(Vec3f(xFactor, yFactor, zFactor));
}

void Transformable::scale(const Vec3f& factor) {
    this->setScale(
        m_scaleFactors.x * factor.x,
        m_scaleFactors.y * factor.y,
        m_scaleFactors.z * factor.z
    );
}

const Transform& Transformable::getTransform() const
{
    if (m_transformNeedUpdate) {
        // Scale components
        float s_x = m_scaleFactors.x;
        float s_y = m_scaleFactors.y;
        float s_z = m_scaleFactors.z;
        // Translation components
        float t_x = -m_position.x * s_x;
        float t_y = -m_position.y * s_y;
        float t_z = -m_position.z * s_z;

        // Rebuild the projection matrix
        m_transform = Transform(s_x, 0.f, 0.f, 0.f,
                                0.f, s_y, 0.f, 0.f,
                                0.f, 0.f, s_z, 0.f,
                                t_x, t_y, t_z, 1.f );
        
        m_transform.combine(m_rotationMatrix);

        m_transformNeedUpdate = false;
    }

    return m_transform;
}