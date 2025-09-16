#ifndef __linalg_hpp__
#define __linalg_hpp__

#include <hexvel-graphics/linalg/vec3.hpp>

float dot(Vec3f left, Vec3f right);

Vec3f normalize(Vec3f vec);

Vec3f cross(Vec3f left, Vec3f right);

#endif // __linalg_hpp__