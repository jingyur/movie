#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 10

typedef struct {
	int row;
 	int col;
 	bool occupy;
} seat;

typedef struct {
	seat seats[MAX_ROW][MAX_COL];
}hall;      	

seat* seat_create(int row, int col, bool occupy);
void seat_print(const seat* s);

bool occupy_seat(hall* h, int row, int col);

hall* init_hall();

void hall_print(const hall* h);
