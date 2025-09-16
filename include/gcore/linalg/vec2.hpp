#ifndef __vec2_hpp__
#define __vec2_hpp__

template <typename T>
class Vec2 {
public:
    Vec2();
    Vec2(T x, T y);

    template <typename U>
    explicit Vec2(const Vec2<U>& vector);

    T x, y;
};

template <typename T>
Vec2<T> operator -(const Vec2<T>& right);

template <typename T>
Vec2<T>& operator +=(Vec2<T>& left, const Vec2<T>& right);

template <typename T>
Vec2<T>& operator -=(Vec2<T>& left, const Vec2<T>& right);

template <typename T>
Vec2<T> operator +(const Vec2<T>& left, const Vec2<T>& right);

template <typename T>
Vec2<T> operator -(const Vec2<T>& left, const Vec2<T>& right);

template <typename T>
Vec2<T> operator *(const Vec2<T>& left, T right);

template <typename T>
Vec2<T> operator *(T left, const Vec2<T>& right);

template <typename T>
Vec2<T>& operator *=(Vec2<T>& left, T right);

template <typename T>
Vec2<T> operator /(const Vec2<T>& left, T right);

template <typename T>
Vec2<T>& operator /=(Vec2<T>& left, T right);

template <typename T>
bool operator ==(const Vec2<T>& left, const Vec2<T>& right);

template <typename T>
bool operator !=(const Vec2<T>& left, const Vec2<T>& right);

#include <gcore/linalg/vec2.inl>

/* Define the most common types */
typedef Vec2<int>           Vec2i;
typedef Vec2<unsigned int>  Vec2u;
typedef Vec2<float>         Vec2f;

#endif /* __vec2_hpp__ */