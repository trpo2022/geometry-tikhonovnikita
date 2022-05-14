TARGET = bin/geometry
CC = gcc
CFLAGS = -I src -Wall -Wextra -Werror -O0 -g
CPPFLAGS = -MMD

$(TARGET) : ./obj/src/geometry/*.o ./obj/src/libgeometry/*.a
	$(CC) $(CFLAGS) -o $@ $^ -lm

./obj/src/geometry/*.o : ./src/geometry/geometry.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

./obj/src/libgeometry/%.a : ./obj/src/libgeometry/%.o 
	ar rcs $@ $^

./obj/src/libgeometry/%.o : ./src/libgeometry/function.c
	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<

run :
	bin/geometry

clean : 
	rm ./bin/geometry

-include main.d hello.d