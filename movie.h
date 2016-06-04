#define MAX_NAME_LEN 128

typedef struct {
	char name[MAX_NAME_LEN+1];
	int rate;
} movie;

void debug(const char* log);

movie* create(const char* name, int rate);

void movie_print(const movie* m);
