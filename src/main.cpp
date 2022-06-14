#include "../include/vec3.hpp"
#include "../include/color.hpp"
#include "../include/ray.hpp"

#include <iostream>

double hit_sphere(const point3& center, double_t radius, const ray& r)
{
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

    // The part of the quad. equation under square root
    auto discriminant = half_b*half_b - a*c;

    if (discriminant < 0)
    {
        return -1.0;
    }
    else
    {
        // Finish the quadratic equation
        return (-half_b - sqrt(discriminant)) / a;
    }
}

/*
 * Simply calculated the color of the ray upon hitting the sphere. Uses surface normals
 * in order to determine the color of the ray.
 * r - A ray being cast from a camera
 * Return - A color in RGB format that will be transformed into ppm format.
 */
color ray_color(const ray& r)
{
    auto t = hit_sphere(point3(0,0,-1), 0.5, r);
    // If we recieve a postivie solution from hit_sphere than there are
    // two possible real answers. This is used to return a single color
    // from the two possible answers.
    if (t > 0.0)
    {
        vec3 N = unit_vector(r.at(t) - vec3(0,0,-1));
        return (0.5 * color(N.x()+1, N.y()+1, N.z()+1));
    }

    vec3 unit_direction = unit_vector(r.direction());
    t = 0.5 * (unit_direction.y() + 1.0);

    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

int main()
{
    // Image
    // Set up image with 16:9 aspect ratio
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // Camera
    // Crate viewport with set height and variable width
    // Focal length: Distance between the projection plane and the projection point
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    // Place the "eye' at <0,0,0>
    auto origin = point3(0, 0, 0);
    // Create two "unit" vectors that are set to the width and height of the viewport
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0, 0, focal_length);

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height - 1; i >= 0; --i)
    {
        std::cerr << "\rScanLines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j)
        {
            auto u = double(j) / (image_width - 1);
            auto v = double(i) / (image_height - 1);

            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}
