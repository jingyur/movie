#include <stdio.h>
#include "movie.h"

int main()
{
	debug("start movie...");

	movie* movie_list[] = {
		create("Limbo", 5),
		create("Inception", 7),
		create("CrazyZoom", 7)
	};

	int len = sizeof(movie_list)/sizeof(movie*);

	printf("movie list length %i\n", len);

	printf("sizeof int: %lu\n", sizeof(int));	// 8, 64bits system, int -> 4
	printf("sizeof movie: %lu\n", sizeof(movie));	// MAX_LEN_LNE(128) + 1 + int, 133
	printf("sizeof movie*: %lu\n", sizeof(movie*));	// 8

	for(int i = 0; i < len; ++i) {
		movie_print(movie_list[i]);
	}

	/*  */

	debug("end movie...");

	return 0;
}
