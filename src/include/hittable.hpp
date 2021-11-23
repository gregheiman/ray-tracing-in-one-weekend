#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"

struct hit_record
{
    point3 p;
    vec3 normal;
    double_t t;
};

class hittable
{
public:
    virtual bool hit(const ray&r, double_t t_min, double_t t_max, hit_record& rec) const = 0;
};

#endif
