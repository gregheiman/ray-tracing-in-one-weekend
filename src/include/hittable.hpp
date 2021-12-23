#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"
#include "vec3.hpp"

struct hit_record
{
    point3 p;
    vec3 normal;
    double_t t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal)
    {
        // Determine if the ray is coming from outside of the object
        front_face = dot(r.direction(), outward_normal) < 0;
        // If the ray is coming from outside the object than we take the outward normal
        // otherwise inverse the outward normal. This results in the normal ray
        // always pointing against the ray
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable
{
public:
    virtual bool hit(const ray&r, double_t t_min, double_t t_max, hit_record& rec) const = 0;
};

#endif
