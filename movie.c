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

movie* movie_append(movie* m1, movie* m2)
{
	movie* p = m1->next;
	if (!p) {
		m1->next = m2;
	} else {
		while(p->next ){
			p = p->next;
		}
		p->next = m2;
	}
	return m1;
}

int movie_count( movie* list)
{
	if(!list){
		return 0;
	} 
		int c= 1;
		movie* p = list;
		while((p = p->next)) {
			++c;
		}
	return c;
}

int movie_hall_count( movie* m)
{
	if(!m || !m->halls){
		return 0;
	} 
		int c = 1;
		hall* p = m->halls;
		while((p = p->next)) {
			++c;
		}
	return c;
}

movie* movie_select(movie* list, int index)
{
	int c = movie_count(list);
	if(index > c) {
		return NULL;
	}
	
	movie* p = list;
	while(--index) {
		p = p->next;
	}
	return p;
}

hall* movie_hall_select(movie* m, int index)
{
	int c = movie_hall_count(m);
	if(index > c) {
		return NULL;
	}
	
	hall* p = m->halls;
	while(--index) {
		p = p->next;
	}
	return p;
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
