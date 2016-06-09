#include <stdbool.h>

#define MAX_ROW 10
#define MAX_COL 10
#define THEATRE_NAME_LEN 64

struct theatre;
struct movie;

typedef struct {
	int row;
 	int col;
	bool preo;
 	bool occupy;
} seat;

typedef struct hall {
	seat** seats;
	int price;

	struct theatre* theatre;
	struct movie* movie;
    struct hall* next;
} hall;      	

typedef struct theatre {
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
hall* hall_price(hall* h, int p);

hall* hall_bind_theatre(hall* h, theatre* t);
hall* hall_bind_movie(hall* h, struct movie* m);

theatre* theatre_create(const char* name);

void theatre_print(const theatre* t);
