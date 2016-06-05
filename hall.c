#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#include "utility.h"
#include "hall.h"

void seat_print(const seat* s)
{
	if(s->occupy) 
		printf("[x]");
	else if(s->preo)
		printf("[+]");
	else
		printf("[_]");      
}

bool hall_occp(hall* h, int r, int c)
{
	seat* s = &(h->seats[r][c]);
	if(s->occupy) {
		debug("want to occupy seat(%i:%i) failed.", r, c);
		return false;
	} else if (s->preo) {
		debug("occupy succeed", r, c);
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
		debug("want to cancel seat(%i:%i) success.", r, c);
		s->preo =false;
		return true;
	}
	return false;
}

hall* init_hall()
{
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

	return h;
}

hall* random_hall_occp(hall* h)
{
    srand(time(NULL));

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

void hall_print(const hall* h)
{
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