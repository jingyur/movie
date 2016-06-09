#define MAX_NAME_LEN 128
#define MAX_PN_LEN 64

struct hall;

typedef struct movie {
	char name[MAX_NAME_LEN+1];
	char director[MAX_PN_LEN+1];
	int rate;
    struct hall* halls;    // 1 movie shows on mulitiple halls
    struct movie* next;    // linked all movies 
} movie;

movie* movie_create(const char* name, const char* director, int rate);
void movie_print(const movie* m);
void movie_print_with_hall(const movie* m);
