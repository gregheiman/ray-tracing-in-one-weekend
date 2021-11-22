cmake_minimum_required(VERSION 3.10)

project(ray_tracer)

set(CMAKE_CXX_VERSION 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(Vec3 vec3.cpp)
add_library(Ray ray.cpp)
add_library(Color color.cpp)

add_executable(ray_tracer main.cpp)

target_include_directories(ray_tracer PUBLIC include)

target_link_libraries(ray_tracer PUBLIC Vec3)
target_link_libraries(ray_tracer PUBLIC Ray)
target_link_libraries(ray_tracer PUBLIC Color)
