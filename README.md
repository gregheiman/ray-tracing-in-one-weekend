
# Ray Tracing In One Weekend
C++ project following the "Ray Tracing in One Weekend" book. Used to learn more about ray tracing, C++, and
computer graphics.

This program is built and tested only on Linux (Fedora 34). As such can not guarantee compatibility with other operating systems.

## Prerequisites
- CMake (Tested on version 3.20.5)
- A build tool for your respective OS (Ex. GNU Make on Linux)
- A C++ compiler (Tested using g++)
- An image viewer that can read `.ppm` file formats (Ex. feh on Linux)
- A terminal from which to build and run the program

## How to Run the Project
1. Clone the project to your computer
2. Navigate into the `/build` directory inside of the project
3. Run the following command: `cmake ../src`
   - This will create the build files for your system
4. Build the project executable inside of the `/build` directory
   - On Linux systems this can be done with the command: `make`
5. Run the project with the following command in the `/build` directory: `ray_tracer` 
   - If you would like to pipe the programs output to a file simply use the following command on Linux systems: `ray_tracer > image.ppm`
