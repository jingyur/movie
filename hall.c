#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "utility.h"
#include "hall.h"
#include "movie.h"

void seat_print(const seat* s)
{
	if(s->occupy) 
		printf("[x]");
	else if(s->preo)
		printf("[+]");
	else
		printf("[_]");      
}

hall* hall_bind_theatre(hall* h, theatre* t)
{
	h->theatre = t;
	return h;
}

hall* hall_bind_movie(hall* h, movie* m)
{
	h->movie = m;

    if(!m->halls) {
        m->halls = h;
        return h;
    }

    /* append this hall to movie's hall list */

    hall* ph = m->halls;
    while(ph->next) {
        ph = ph->next;
    }
    ph->next = h;

	return h;
}

hall*  hall_price(hall* h, int p)
{
	h->price = p;
	return h;
}
		
bool hall_occp(hall* h, int r, int c)
{
	seat* s = &(h->seats[r][c]);
	if(s->occupy) {
		debug("want to occupy seat(%i:%i) failed.", r, c);
		return false;
	} else if (s->preo) {
		//debug("occupy succeed", r, c);
		s->occupy = true;
		return true;
	} else {
		return false;
	}
}

bool hall_preo(hall* h, int r, int c)
{
	seat* s = &(h->seats [r][c]);
	if(s->occupy) {
		debug("want to occupy seat(%i:%i) failed.", r, c);
		return false;
	} else if (s->preo){
		debug("want to preo seat(%i:%i) failed.", r, c);
		return false;
	} else {
                s->preo = true;
		return true;
	}
}

bool hall_preo_cancel(hall* h, int r, int c)
{
	seat* s = &(h->seats [r][c]);
	if(s->occupy) {
		debug("want to cancel seat(%i:%i) failed.", r, c);
		return false;
	} else if (s->preo){
		//debug("want to cancel seat(%i:%i) success.", r, c);
		s->preo =false;
		return true;
	}
	return false;
}

hall* init_hall()
{
    /* init hall's seats */

    seat** seats = (seat**) malloc(sizeof(seat*) * MAX_ROW);

	for(int i = 0; i < MAX_ROW; ++i) {
        seats[i] = (seat*) malloc(sizeof(seat) * MAX_COL);
		for(int j = 0; j < MAX_COL; ++j) {
			seat* s = &(seats[i][j]);
			s->row = i;
			s->col = j;
			s->preo=false;
			s->occupy = false;
		}
	}

	hall* h = (hall*)malloc(sizeof(hall));
    h->seats = seats;

    /* init hall's theatre and movie */

    h->theatre = NULL;
    h->movie = NULL;
    h->next = NULL;

	return h;
}

hall* random_hall_occp(hall* h)
{
    for(int i = 0; i < MAX_ROW; ++i) {
        for(int j = 0; j < MAX_COL; ++j) {
            if(rand() % 100 > 80) {
                hall_preo(h, i, j);
                hall_occp(h, i, j);
            }
        }
    }
    return h;
}

float hall_use_rate(const hall* h)
{
	int total = 0;
	int used = 0;
	for(int i = 0; i < MAX_ROW; ++i) {
		for(int j = 0; j <MAX_COL; ++j) {
			total ++;
			seat* s=&(h->seats [i][j]);
			if (s->occupy)
				used ++;
		}
	}
	float use_rate;
	use_rate = (float)used / total *100;
	return use_rate;
}

void hall_print(const hall* h)
{
    printf("the use_rate of this hall is %.2f%%\n", hall_use_rate(h) );
    printf("the price of this hall is %i\n", h->price);
    printf("the hall is belong to this theatre %s\n", h->theatre->name);
    printf("the hall will play movie %s\n", h->movie->name);

    printf("---------- SCREEN ------------\n");

	seat** seats = h->seats;
	for(int i = 0; i < MAX_ROW; ++i) {
		for(int j = 0; j < MAX_COL; ++j) {
			seat_print(&seats[i][j]);
		}
		printf("\n");
	}
    printf("------------------------------\n");
}

theatre* theatre_create(const char* name)
{
	theatre* t = (theatre*)malloc(sizeof(theatre));
	strncpy(t->name, name, strlen(name)+1);
	return t;
}

void theatre_print(const theatre* t)
{
	debug("Theatre info: name: %s",  t->name);
}












