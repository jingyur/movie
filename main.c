#include <stdio.h>
#include "utility.h"
#include "movie.h"
#include "seat.h"

int main()
{
	debug("start movie...");

	hall* h = init_hall();
	occupy_seat(h, 5, 7);
	occupy_seat(h, 2, 3);
	occupy_seat(h, 9, 4);
	//hall_print(h);

	//movie* movie_list[] = {
	//	create("Limbo", "ab", 5),
	//	create("Inception","bc", 7),
	//	create("CrazyZoom","cd", 7)
	//};

	//int len = sizeof(movie_list)/sizeof(movie*);

	//debug("movie list length %i\n", len);

	//for(int i = 0; i < len; ++i) {
	//	movie_print(movie_list[i]);
	//}

	debug("end movie...");

	return 0;
}



