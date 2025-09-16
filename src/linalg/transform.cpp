#include <hexvel-graphics/linalg/transform.hpp>

#include <cstring>

Transform Transform::Identity(1.f, 0.f, 0.f, 0.f,
                              0.f, 1.f, 0.f, 0.f,
                              0.f, 0.f, 1.f, 0.f,
                              0.f, 0.f, 0.f, 1.f );

Transform::Transform(float m00, float m01, float m02, float m03,
                     float m10, float m11, float m12, float m13,
                     float m20, float m21, float m22, float m23,
                     float m30, float m31, float m32, float m33 ) :
    m_matrix{m00, m01, m02, m03,
             m10, m11, m12, m13,
             m20, m21, m22, m23,
             m30, m31, m32, m33 }
{}

Transform::Transform(const float *matrix) {
    memcpy(m_matrix, matrix, sizeof(m_matrix));
}

Transform::Transform(const Transform& t) {
    memcpy(m_matrix, t.m_matrix, sizeof(m_matrix));
}

Transform& Transform::combine(const Transform& transform) {
    float m[16] = {0};
    const float *ml = m_matrix;
    const float *mr = transform.getMatrix();

    for (int i=0; i<4; i++)
        for (int j=0; j<4; j++)
            for (int k=0; k<4; k++)
                m[4 * i + j] += mr[4 * i + k] * ml[4 * k + j];

    memcpy(m_matrix, m, sizeof(m_matrix));

    return *this;
}

const float* Transform::getMatrix() const {
    return m_matrix;
}

void Transform::operator=(const Transform& transfrom) {
    memcpy(m_matrix, transfrom.m_matrix, sizeof(m_matrix));
}