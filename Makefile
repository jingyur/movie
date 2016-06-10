a.out: main.c utility.c movie.c hall.c io.c
	gcc -c utility.c movie.c hall.c io.c
	gcc main.c utility.o movie.o hall.o io.o -o a.out

test: test.c utility.c movie.c hall.c io.c
	gcc -c utility.c movie.c hall.c io.c
	gcc test.c utility.o movie.o hall.o io.o -o test

clean:
	rm -rf *.o
	rm -rf a.out test
