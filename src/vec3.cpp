#include "include/vec3.h"

#include <iostream>

using std::sqrt;

double_t vec3::x() const
{
    return e[0];
}

double_t vec3::y() const
{
    return e[1];
}

double_t vec3::z() const
{
    return e[2];
}

vec3 vec3::operator-() const
{
    return vec3(-e[0], -e[1], -e[2]);
}

double_t vec3::operator[](int16_t i) const
{
    return e[i];
}

double_t &vec3::operator[](int16_t i)
{
    return e[i];
}

vec3 &vec3::operator+=(const vec3 &v)
{
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
}

vec3 &vec3::operator*=(const double_t t)
{
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

vec3 &vec3::operator/=(const double_t t)
{
    return *this *= 1 / t;
}

double_t vec3::length() const
{
    return sqrt(length_squared());
}

double_t vec3::length_squared() const
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

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
