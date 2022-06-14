#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class vec3 {
public:
    vec3() = default;
    vec3(double_t e0, double_t e1, double_t e2)
    {
        e[0] = e0;
        e[1] = e1;
        e[2] = e2;
    }

    double_t x() const;

    double_t y() const;

    double_t z() const;

    vec3 operator-() const;

    double_t operator[](int16_t i) const;

    double_t &operator[](int16_t i);

    vec3 &operator+=(const vec3 &v);

    vec3 &operator*=(const double_t t);

    vec3 &operator/=(const double_t t);

    double_t length() const;

    double_t length_squared() const;

private:
    double_t e[3] = {0, 0, 0};
};

// Type aliases for vec3
using point3 = vec3; // 3D point
using color = vec3;  // RGB color


// vec3 Utility Functions
inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
    return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
    return vec3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline vec3 operator*(double_t t, const vec3 &v)
{
    return vec3(t * v.x(), t * v.y(), t * v.z());
}

inline vec3 operator*(const vec3 &v, double_t t)
{
    return t * v;
}

inline vec3 operator/(vec3 v, double_t t)
{
    return (1 / t) * v;
}

inline double_t dot(const vec3 &u, const vec3 &v)
{
    return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline vec3 cross(const vec3 &u, const vec3 &v)
{
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

inline vec3 unit_vector(vec3 v)
{
     return v / v.length();
}
#endif
