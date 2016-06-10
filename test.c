#include <stdlib.h>
#include <time.h>

#include "utility.h"
#include "movie.h"
#include "hall.h"

hall* init_hall_random(int p, theatre* t, movie* m)
{
	hall* h = init_hall();
	random_hall_occp(h);
	hall_price(h, p);
	hall_bind_theatre(h, t);
	hall_bind_movie(h, m);
	//hall_print(h);
	return h;
}

void test_hall2()
{
	theatre* wd = theatre_create("Wanda");
	theatre* xm = theatre_create("Xingmei");

    movie* mw = movie_create("Wow", "John", 9);
    movie* mx = movie_create("X-Man", "Monica", 7);
    movie* mb = movie_create("Bird", "Jack", 8);

    movie_append(mw,mx);
    movie_append(mw,mb);

	init_hall_random(70,wd, mw);
	init_hall_random(40,wd, mw);
	init_hall_random(50,wd, mx);
	init_hall_random(90,wd, mx);
	init_hall_random(150,wd, mb);
	init_hall_random(130,xm, mw);
	init_hall_random(120,xm, mw);
	init_hall_random(100,xm, mx);
	init_hall_random(80,xm, mb);
/*
    movie_print_with_hall(mw);
    movie_print_with_hall(mx);  */
    movie_print_with_hall(mb);

	debug("movie list len %i", movie_count(mw));
	debug("movie shows on these halls: %i\n", movie_hall_count(mw));
	
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
        srand(time(NULL));
	test_hall2();
	return 0;
}
