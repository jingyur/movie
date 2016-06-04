#define MAX_NAME_LEN 128
#define MAX_PN_LEN 64

typedef struct {
	char name[MAX_NAME_LEN+1];
	char director[MAX_PN_LEN+1];
	int rate;
} movie;


movie* create(const char* name, const char* director, int rate);

void movie_print(const movie* m);
