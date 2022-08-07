gcc_args = -Wall -Werror -std=c11
game: zq.o
	gcc $(gcc_args) zq.o game.c -g -o game
zq.o: zq.h zq.c
	gcc $(gcc_args) zq.c -g -c -o zq.o
clean:
	rm -f zq.o game
