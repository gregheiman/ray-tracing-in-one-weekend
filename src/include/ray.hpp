#ifndef RAY_H
#define RAY_H

#include "vec3.hpp"

class ray
{
 public:
    ray() {}
    ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}

    point3 origin() const;

    vec3 direction() const;
    
    point3 at(double_t t) const;

 private:
    point3 orig;
    vec3 dir;
};

#endif
