#include "include/vec3.h"
#include "include/color.h"

#include <iostream>

int main()
{
    // Image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int i = image_height - 1; i >= 0; --i)
    {
        std::cerr << "\rScanLines remaining: " << i << ' ' << std::flush;
        for (int j = 0; j < image_width; ++j)
        {
            auto r = double(i) / (image_width - 1);
            auto g = double(j) / (image_height - 1);
            auto b = 0.25;

            color pixel_color(r, g, b);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
}
