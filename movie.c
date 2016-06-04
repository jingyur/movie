#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "movie.h"

void debug(const char* log)
{
	printf("%s\n", log);	// print to std output
	// print to file 
}

movie* create(const char* name, const char* director, int rate)
{
	movie* m = (movie*)malloc(sizeof(movie));
	strncpy(m->name, name, strlen(name));
        strncpy(m->director, director, strlen(director));
	m->rate = rate;
	return m;
}

void movie_print(const movie* m)
{
	printf("Move info: name: %s, director: %s, rate: %i\n", m->name, m->director, m->rate);
}
