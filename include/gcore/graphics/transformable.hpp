#ifndef __transformable_hpp__
#define __transformable_hpp__

#include <gcore/linalg/vec3.hpp>
#include <gcore/linalg/transform.hpp>

class Transformable
{
public:
    Transformable();

    /* Public methods */

    void setPosition(float x, float y, float z);
 
    void setPosition(const Vec3f& position);
 
    void setRotation(float angle, Vec3f axis);
 
    void setScale(float xFactor, float yFactor, float zFactor);
 
    void setScale(const Vec3f& factors);
 
    const Vec3f& getPosition() const;
 
    const float* getRotation() const;
 
    const Vec3f& getScale() const;
 
    void move(float xOffset, float yOffset, float zOffset);
 
    void move(const Vec3f& offset);
 
    void scale(float xFactor, float yFactor, float zFactor);
 
    void scale(const Vec3f& factor);
 
    const Transform& getTransform() const;
 
private:
    /* Private fields */
    
    Vec3f             m_position;
    Vec3f             m_scaleFactors;
    Transform         m_rotationMatrix;
    mutable Transform m_transform;
    mutable bool      m_transformNeedUpdate;
    mutable Transform m_inverseTransform;
    mutable bool      m_inverseTransformNeedUpdate;
};

#endif // __transformable_hpp__