# This is an example Makefile for a countwords program.  This
# program uses both the scanner module and a counter module.
# Typing 'make' or 'make count' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -g -Wall
INCLUDES = -I./src/include
LFLAGS = -L./lib
SYSTEMINCLUDES =

# typing 'make' will invoke the first target entry in the file
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: ray_tracer

# Create executable file
ray_tracer: lib/main.o lib/vec3.o lib/color.o lib/ray.o
	$(CC) $(CFLAGS) $(INCLUDES) $(LFLAGS) $(SYSTEMINCLUDES) -o ray_tracer lib/main.o lib/vec3.o lib/color.o lib/ray.o

# Create the individual objects
lib/main.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/main.cpp -o lib/main.o

lib/vec3.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/vec3.cpp -o lib/vec3.o

lib/color.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/color.cpp -o lib/color.o

lib/ray.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c src/ray.cpp -o lib/ray.o

# Run with make clean. Removes all object files
clean:
	$(RM) lib/*.o *.o *.ppm ray_tracer
