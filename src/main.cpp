#include "../include/sphere.hpp"
#include "../include/color.hpp"
#include "../include/hittable_list.hpp"
#include "../include/rtweekend.hpp"
#include "../include/camera.hpp"

#include <iostream>

/*
 * Simply calculated the color of the ray upon hitting the sphere. Uses surface normals
 * in order to determine the color of the ray.
 * r - A ray being cast from a camera
 * Return - A color in RGB format that will be transformed into ppm format.
 */
color ray_color(const ray& r, const hittable& world)
{
    hit_record rec;

    if (world.hit(r, 0, infinity, rec))
    {
        return 0.5 * (rec.normal + color(1,1,1));
    }

    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main()
{
    // Image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);
    const int samples_per_pixel = 100;

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    // Camera
    camera cam;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height - 1; i >= 0; --i)
    {
        std::cerr << "\rScanLines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j)
        {
            color pixel_color(0, 0, 0);
            for (int s = 0; s < samples_per_pixel; ++s)
            {
                auto u = (i + random_double()) / (image_width - 1);
                auto v = (j + random_double()) / (image_height - 1);

                ray r = cam.get_ray(u, v);
                pixel_color += ray_color(r, world);
            }
            write_color(std::cout, pixel_color, samples_per_pixel);
        }
    }

    std::cerr << "\nDone.\n";
}
