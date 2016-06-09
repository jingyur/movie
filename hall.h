#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 10
#define THEATRE_NAME_LEN 64
typedef struct {
	int row;
 	int col;
	bool preo;
 	bool occupy;
} seat;

typedef struct {
	seat** seats;
	int price;
} hall;      	

typedef struct {
	char name[THEATRE_NAME_LEN+1];
}theatre;

hall* init_hall();
hall* random_hall_occp(hall* h);

void seat_print(const seat* s);

float hall_use_rate(const hall* h);
bool hall_occp(hall* h, int row, int col);
bool hall_preo(hall* h, int row, int col);
bool hall_preo_cancel(hall* h, int row, int col);
void hall_print(const hall* h);
void hall_price(hall* h, int p);

theatre* theatre_create(const char* name);

void theatre_print(const theatre* t);
