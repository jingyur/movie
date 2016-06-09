#include <stdlib.h>

#include "utility.h"
#include "movie.h"
#include "hall.h"

hall* init_hall_random(int p)
{
	hall* h = init_hall();
	random_hall_occp(h);
	hall_price(h, p);
	hall_print(h);
	return h;
}

void test_hall2()
{
	init_hall_random(70);
	init_hall_random(40);
	init_hall_random(50);
	init_hall_random(90);
	init_hall_random(150);
	init_hall_random(130);
	init_hall_random(100);
	init_hall_random(80);
}

void test_hall()
{
	hall* h = init_hall();
    	random_hall_occp(h);
	hall_price(h,80);
	hall_print(h);

	hall_preo(h, 3, 5);	
	hall_print(h);
		
	hall_preo(h, 7, 4);	
	hall_print(h);

	hall_preo_cancel(h, 7, 4);	
	hall_print(h);
}

void test_movie()
{
	movie* movie_list[] = {
		movie_create("Limbo", "ab", 5),
		movie_create("Inception","bc", 7),
		movie_create("CrazyZoom","cd", 7)
	};

	int len = sizeof(movie_list)/sizeof(movie*);

	debug("movie list length %i", len);

	for(int i = 0; i < len; ++i) {
		movie_print(movie_list[i]);
	}
}

void test_theatre()
{
	theatre* theatre_list[] = {
		theatre_create("Wanda"),
		theatre_create("Xingmei"),
	};

	int len = sizeof(theatre_list)/sizeof(theatre*);

	debug("theatre list length %i", len);

	for(int i = 0; i < len; ++i) {
		theatre_print(theatre_list[i]);
	}
}


int main()
{
	test_hall2();
	return 0;
}
