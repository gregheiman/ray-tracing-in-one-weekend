IDIR=./include
ODIR=./obj
LDIR=./lib

CC=clang++
CFLAGS=-O3 -std=c++17 -I$(IDIR)

_DEPS = ray.hpp vec3.hpp hittable_list.hpp hittable.hpp color.hpp sphere.hpp
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = ray.o vec3.o hittable_list.o color.o sphere.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o : src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ray_tracer : $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ ray_tracer $(INCDIR)/*~
