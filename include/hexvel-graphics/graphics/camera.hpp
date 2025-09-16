#ifndef __camera_hpp__ 
#define __camera_hpp__

#include <hexvel-graphics/linalg/vec3.hpp>
#include <hexvel-graphics/linalg/transform.hpp>

class Camera {
public:
    Camera();

    /* Public methods */

    void lookAt(float yaw, float pitch);

    void rotate(float dYaw, float dPitch);

    void setWorldUp(Vec3f);

    void setPosition(Vec3f);

    void move(Vec3f);

    const Transform& getViewTransform() const;

    const Transform& getProjTransform() const;

private:
    /* Private fields */
    
    Vec3f             m_worldUp;
    float             m_yaw;
    float             m_pitch;
    Vec3f             m_position;
    mutable bool      m_viewNeedUpdate;
    mutable Transform m_viewTransform;
    mutable bool      m_projNeedUpdate;
    mutable Transform m_projTransform;
};

#endif // __camera_hpp__