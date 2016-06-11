#include "utility.h"
#include "movie.h"
#include "hall.h"
#include <stdlib.h>
#include <time.h>

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

    movie_print_with_hall(mw);
    movie_print_with_hall(mx);  
    movie_print_with_hall(mb);

	debug("movie list len %i", movie_count(mw));
	debug("movie shows on these halls: %i\n", movie_hall_count(mw));

	debug("movie select : %s", (movie_select(mw, 2))->name);

	movie* pm = movie_select(mw, 2);
	hall* ph = movie_hall_select(pm, 2);
	debug("movie(%s) hall select : %s, price: %d", pm->name, ph->theatre->name, ph->price);
	hall_print(ph);

	pm = movie_select(mw, 3);
	ph = movie_hall_select(pm, 1);
	debug("movie(%s) hall select : %s, price: %d", pm->name, ph->theatre->name, ph->price);
        hall_print(ph); 

	pm = movie_select(mw, 1);
	ph = movie_hall_select(pm, 3);
	debug("movie(%s) hall select : %s, price: %d", pm->name, ph->theatre->name, ph->price);
        hall_print(ph); 
}


int main()
{
	debug("start movie...");

	debug("end movie...");

	return 0;
}



