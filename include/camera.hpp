#ifndef _CAMERA_H
#define _CAMERA_H

#include "rtweekend.hpp"

class camera
{
public:
    camera();

    ray get_ray(double u, double v) const;

private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horizontal;
    vec3 vertical;
};

#endif

