#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utility.h"
#include "movie.h"
#include "hall.h"

hall* random_hall_occp(hall* h)
{
    srand(time(NULL));

    for(int i = 0; i < MAX_ROW; ++i) {
        for(int j = 0; j < MAX_COL; ++j) {
            if(rand() % 100 > 80) {
                hall_occp(h, i, j);
            }
        }
    }
    return h;
}

int main()
{
	debug("start movie...");

	hall* h = init_hall();
    random_hall_occp(h);
	hall_print(h);

	debug("end movie...");

	return 0;
}



