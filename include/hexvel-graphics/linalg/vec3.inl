template <typename T>
inline Vec3<T>::Vec3() :
x(0),
y(0),
z(0)
{ }

template <typename T>
inline Vec3<T>::Vec3(T X, T Y, T Z) :
x(X),
y(Y),
z(Z)
{ }

template <typename T>
template <typename U>
inline Vec3<T>::Vec3(const Vec3<U>& vec) :
x(static_cast<T>(vec.x)),
y(static_cast<T>(vec.y)),
z(static_cast<T>(vec.z))
{ }

template <typename T>
inline Vec3<T> operator -(const Vec3<T>& right)
{
    return Vec3<T>(-right.x, -right.y, -right.z);
}

template <typename T>
inline Vec3<T>& operator +=(Vec3<T>& left, const Vec3<T>& right)
{
    left.x += right.x;
    left.y += right.y;
    left.z += right.z;
    return left;
}

template <typename T>
inline Vec3<T>& operator -=(Vec3<T>& left, const Vec3<T>& right)
{
    left.x -= right.x;
    left.y -= right.y;
    left.z -= right.z;
    return left;
}

template <typename T>
inline Vec3<T> operator +(const Vec3<T>& left, const Vec3<T>& right)
{
    return Vec3<T>(left.x + right.x, left.y + right.y, left.z + right.z);   
}

template <typename T>
inline Vec3<T> operator -(const Vec3<T>& left, const Vec3<T>& right)
{
    return Vec3<T>(left.x - right.x, left.y - right.y, left.z - right.z); 
}

template <typename T>
inline Vec3<T> operator *(const Vec3<T>& left, T right)
{
    return Vec3<T>(left.x * right, left.y * right, left.z * right);
}

template <typename T>
inline Vec3<T> operator *(T left, const Vec3<T>& right)
{
    return Vec3<T>(left * right.x, left * right.y, left * right.z);
}

template <typename T>
inline Vec3<T>& operator *=(Vec3<T>& left, T right)
{
    left.x *= right;
    left.y *= right;
    left.z *= right;
    return left;
}

template <typename T>
inline Vec3<T> operator /(const Vec3<T>& left, T right)
{
    return Vec3<T>(left.x / right, left.y / right, left.z / right);
}

template <typename T>
inline Vec3<T>& operator /=(Vec3<T>& left, T right)
{
    left.x /= right;
    left.y /= right;
    left.z /= right;
    return left;
}

template <typename T>
inline bool operator ==(const Vec3<T>& left, const Vec3<T>& right)
{
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}

template <typename T>
inline bool operator !=(const Vec3<T>& left, const Vec3<T>& right)
{
    return (left.x != right.x) || (left.y != right.y) || (left.z != right.z);
}