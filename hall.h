#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 10

typedef struct {
	int row;
 	int col;
 	bool occupy;
} seat;

typedef struct {
	seat** seats;
} hall;      	

hall* init_hall();

void seat_print(const seat* s);

bool hall_occp(hall* h, int row, int col);
void hall_print(const hall* h);
