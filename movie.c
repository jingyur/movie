#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "utility.h"
#include "movie.h"
#include "hall.h"

movie* movie_create(const char* name, const char* director, int rate)
{
	movie* m = (movie*)malloc(sizeof(movie));
	strncpy(m->name, name, strlen(name)+1);
    	strncpy(m->director, director, strlen(director)+1);
	m->rate = rate;

    m->next = NULL;
    m->halls = NULL;

	return m;
}

void movie_print(const movie* m)
{
	debug("Move info: name: %s, director: %s, rate: %i", 
            m->name, m->director, m->rate);
}

void movie_print_with_hall(const movie* m)
{
    printf("\n======== MOVIE START =======\n");

    movie_print(m);

    hall* h = m->halls;
    while(h) {
        hall_print(h);
        h = h->next;
    }

    printf("\n========= MOVIE END ========\n");
}
