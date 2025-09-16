#include "linalg.hpp"

#include <cmath>

float dot(Vec3f left, Vec3f right) {
    return left.x * right.x + left.y * right.y + left.z * right.z;
}

Vec3f cross(Vec3f left, Vec3f right) {
    return Vec3f(left.y * right.z - right.y * left.z,
                 left.z * right.x - right.z * left.x,
                 left.x * right.y - right.x * left.y );
}

Vec3f normalize(Vec3f vec) {
    float invSqrt = 1.f / sqrt(dot(vec, vec));
    return vec * invSqrt;
}