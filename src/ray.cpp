#include "include/ray.hpp"

point3 ray::origin() const
{
    return orig;
}

point3 ray::direction() const
{
    return dir;
}

/*
 * Ray can be thought of as function P(t) = A + tb
 * P is the 3D position along a line in 3D
 * A is the ray origin
 * b is the ray direction
 * t moves the point along the ray
 */
point3 ray::at(double_t t) const
{
    return orig + t*dir;
}
