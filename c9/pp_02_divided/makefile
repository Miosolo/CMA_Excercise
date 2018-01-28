pp_02: main.o randomWalk.o
	gcc -o pp_02 main.o randomWalk.o

main.o: main.c randomWalk.h
	gcc -c main.c

randomWalk.o: randomWalk.c randomWalk.h
	gcc -c randomWalk.c