#ifndef __transform_hpp__
#define __transform_hpp__

class Transform
{
public:
    Transform() = default;

    Transform(float m00, float m01, float m02, float m03,
              float m10, float m11, float m12, float m13,
              float m20, float m21, float m22, float m23,
              float m30, float m31, float m32, float m33 );

    Transform(const float *matrix);

    Transform(const Transform&);

    /* Public methods */

    Transform& combine(const Transform&);

    const float* getMatrix() const;

    void operator=(const Transform& transfrom);

    /* Static fields */

    static Transform Identity;  // Identity matrix

private:
    /* Private fields */

    float m_matrix[16];
};

#endif // __transform_hpp__