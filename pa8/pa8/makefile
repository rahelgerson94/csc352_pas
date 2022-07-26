gcc_args = -Wall -Werror -std=c11
generator: generator.c 3d.o
	gcc $(gcc_args) 3d.o generator.c -g -o generator
3d.o: 3d.c 3d.h
	gcc $(gcc_args) 3d.c -c -g -o 3d.o
clean:
	rm -f 3d.o generator
