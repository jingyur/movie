#include <string.h>
#include <stdlib.h>

#include "utility.h"
#include "movie.h"

movie* movie_create(const char* name, const char* director, int rate)
{
	movie* m = (movie*)malloc(sizeof(movie));
	strncpy(m->name, name, strlen(name)+1);
    	strncpy(m->director, director, strlen(director)+1);
	m->rate = rate;
	return m;
}

void movie_print(const movie* m)
{
	debug("Move info: name: %s, director: %s, rate: %i", 
            m->name, m->director, m->rate);
}
