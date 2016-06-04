#include <stdlib.h>

#include "utility.h"
#include "movie.h"
#include "hall.h"

int main()
{
	movie* movie_list[] = {
		create("Limbo", "ab", 5),
		create("Inception","bc", 7),
		create("CrazyZoom","cd", 7)
	};

	int len = sizeof(movie_list)/sizeof(movie*);

	debug("movie list length %i", len);

	for(int i = 0; i < len; ++i) {
		movie_print(movie_list[i]);
	}
}
