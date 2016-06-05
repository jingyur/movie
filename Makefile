a.out: main.c utility.c movie.c hall.c
	gcc -c utility.c movie.c hall.c
	gcc main.c utility.o movie.o hall.o -o a.out

test: test.c utility.c movie.c hall.c
	gcc -c utility.c movie.c hall.c
	gcc test.c utility.o movie.o hall.o -o test

clean:
	rm -rf *.o
	rm -rf a.out test
