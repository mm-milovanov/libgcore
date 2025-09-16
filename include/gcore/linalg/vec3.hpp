#ifndef __vec3_hpp__
#define __vec3_hpp__

template <typename T>
class Vec3 {
public:
    Vec3();
    Vec3(T x, T y, T z);

    template <typename U>
    explicit Vec3(const Vec3<U>& vector);

    T x, y, z;
};

template <typename T>
Vec3<T> operator -(const Vec3<T>& right);

template <typename T>
Vec3<T>& operator +=(Vec3<T>& left, const Vec3<T>& right);

template <typename T>
Vec3<T>& operator -=(Vec3<T>& left, const Vec3<T>& right);

template <typename T>
Vec3<T> operator +(const Vec3<T>& left, const Vec3<T>& right);

template <typename T>
Vec3<T> operator -(const Vec3<T>& left, const Vec3<T>& right);

template <typename T>
Vec3<T> operator *(const Vec3<T>& left, T right);

template <typename T>
Vec3<T> operator *(T left, const Vec3<T>& right);

template <typename T>
Vec3<T>& operator *=(Vec3<T>& left, T right);

template <typename T>
Vec3<T> operator /(const Vec3<T>& left, T right);

template <typename T>
Vec3<T>& operator /=(Vec3<T>& left, T right);

template <typename T>
bool operator ==(const Vec3<T>& left, const Vec3<T>& right);

template <typename T>
bool operator !=(const Vec3<T>& left, const Vec3<T>& right);

#include <gcore/linalg/vec3.inl>

/* Define the most common types */
typedef Vec3<int>           Vec3i;
typedef Vec3<unsigned int>  Vec3u;
typedef Vec3<float>         Vec3f;

#endif /* __vec3_hpp__ */