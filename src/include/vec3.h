#ifndef VEC3_H
#define VEC3_H

#include <cmath>

class vec3 {
public:
    vec3() : e{0, 0, 0} {}
    vec3(double_t e0, double_t e1, double_t e2) : e{e0, e1, e2} {}

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
     double_t e[3];
};

// Type aliases for vec3
using point3 = vec3; // 3D point
using color = vec3;  // RGB color


#endif
