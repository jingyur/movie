#include "utility.h"
#include "movie.h"
#include "hall.h"
#include "io.h"
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

void start()
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

	do_run(mw);
}

int main()
{
	debug("start movie...");
	start();
	debug("end movie...");

	return 0;
}



