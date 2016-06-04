#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "utility.h"
#include "seat.h"

seat* seat_create(int row, int col, bool occupy)
{
	seat* s = (seat*)malloc(sizeof(seat));
	s->row = row;
	s->col = col;
	s->occupy = occupy;
	return s;
}

void seat_print(const seat* s)
{
	if(s->occupy == true) {
		debug("[x]");
	} else {
		debug("[_]");
	}
}

bool occupy_seat(hall* h, int r, int c)
{
	seat* s = &(h->seats[r][c]);
	if(s->occupy) {
		debug("want to occupy seat(%i:%i) failed.", r, c);
		return false;
	} else {
		s->occupy = true;
		return true;
	}
}

hall* init_hall()
{
	hall* h = (hall*)malloc(sizeof(hall));
	seat** seats = h->seats; 

	for(int i = 0; i < MAX_ROW; ++i) {
		for(int j = 0; j < MAX_COL; ++j) {
			seat* s = &seats[i][j];
			s->row = i;
			s->col = j;
			s->occupy = false;
		}
	}

	return h;
}

void hall_print(const hall* h)
{
	seat** seats = h->seats;
	for(int i = 0; i < MAX_ROW; ++i) {
		for(int j = 0; j < MAX_COL; ++j) {
			const seat* s = &seats[i][j];
			seat_print(s);
		}
		debug("\n");
	}
}
