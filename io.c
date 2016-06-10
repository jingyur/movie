#include <stdio.h>

#include "utility.h"
#include "hall.h"
#include "movie.h"
#include "io.h"

#define MAX_INPUT 256

movie* io_sel_movie(movie* list)
{
    printf("Movie list: \n");
    int i = 1;
    movie* p = list;
    while(p) {
        printf("[%d] %s, director: %s, rate: %d\n", i, p->name, p->director, p->rate);
        p = p->next;
        ++i;
    }

    int total = movie_count(list);
    int sel = 0;
    int ret = 0;
    char line[MAX_INPUT];
    movie* m = NULL;

    while(1) {
        fgets(line, sizeof(line), stdin);
        ret = sscanf(line, "%d", &sel);

        if(ret == 0) {
            printf("Error select, not number.\n");
        } else if(sel > 0 && sel <= total) {
            printf("select [%d] is ok.\n", sel);
            m = movie_select(list, sel);
            break; 
        } else {
            printf("Error select, not in the range.\n");
        }
    }

    return m;
}

hall* io_sel_hall(movie* m)
{
    printf("Movie %s has halls: \n", m->name);
    int i = 1;
    hall* p = m->halls;
    printf("[r] will return back to select movie.\n");
    while(p) {
        printf("[%d] theatre %s, price: %d, used rate: %.2f\n", 
                i, p->theatre->name, p->price, hall_use_rate(p));
        p = p->next;
        ++i;
    }

    int total = movie_hall_count(m);
    int sel = 0;
    char selc = '\0';
    int ret = 0;
    char line[MAX_INPUT];
    hall* h = NULL;

    while(1) {
        fgets(line, sizeof(line), stdin);
        ret = sscanf(line, "%d", &sel);

        if(ret == 0) {
            ret = sscanf(line, "%c", &selc);
            if(ret == 0) {
                printf("Error hall select, not number or r(return).\n");
            } else if(selc == 'r') {
                printf("Okay, will return back to movie select(step1).\n");
                h = NULL;
                break;
            } else {
                printf("Error hall select(%c), not number nor r(return).\n", selc);
            }
        } else if(sel > 0 && sel <= total) {
            h = movie_hall_select(m, sel);
            printf("select [%d] is ok, price: %d, rate: %.2f.\n", 
                    sel, h->price, hall_use_rate(h));
            break;
        } else {
            printf("Error select, not int the range.\n");
        }
    }

    return h;
}

seat* io_sel_seat(hall* h)
{
    hall_print(h);
    printf("[r] will return back to select hall.\n");
    printf("select seat by input: row,col\n");

    int row = 0;
    int col = 0; 
    int ret = 0;
    char selc = '\0';
    char line[MAX_INPUT];
    seat* s = NULL;

    while(1) {
        fgets(line, sizeof(line), stdin);   
        ret = sscanf(line, "%d,%d", &row, &col);

        if(ret == 0) {
            ret = sscanf(line, "%c", &selc);
            if(ret == 0) {
                printf("Error seat(row,col) select.\n");
            } else if(selc == 'r') {
                printf("Okay, will return back to hall select(step2).\n");
                s = NULL;
                break;
            } else {
                printf("Erorr seat(row,col) select.\n");
            }
        } else {
            if (row > MAX_ROW || col > MAX_COL) {
                printf("Error seat(row,col) select, not in the range.\n");
            } else if((s = hall_preo(h, row - 1, col - 1))) {
                printf("Select seat(%d,%d) ok.\n", row, col);
                break;
            } else {
                printf("Error seat(row,col) select, seat is pre occupied.\n");
            }
        }
    }

    return s;
}

bool io_confirm_seat(hall* h, seat* s)
{
    char selc = '\0';
    int ret = 0;
    char line[MAX_INPUT];

    printf("[r/c/n] cancel and return back to select seat.\n");
    printf("[y] confirm the seat and end of this process.\n");

    while(1) {
        fgets(line, sizeof(line), stdin);
        ret = sscanf(line, "%c", &selc);

        if(ret == 0) {
            printf("Error confirm input.\n");
        } else if(selc == 'r' || selc == 'c' || selc == 'n') {
            hall_preo_cancel(h, s->row, s->col);
            return false;
        } else if(selc == 'y') {
            hall_occp(h, s->row, s->col);
            return true;
        } else {
            printf("Error confirm input.");
        }
    }

    return false;
}

void do_run(movie* list)
{
    movie* m;
    hall* h;
    seat* s;

    while(1) {
SEL_M:
        m = io_sel_movie(list);

SEL_H:
        h = io_sel_hall(m);
        if(!h) {
            goto SEL_M;
        } 
       
SEL_S:
        s = io_sel_seat(h);
        if(!s) {
            goto SEL_H;
        }

        hall_print(h);

        if(io_confirm_seat(h, s)) {     // confirmed
            printf("*********************\n");
            printf("Movie(%s), Theatre(%s), Seat(%d,%d), price(%d), END.\n",
                    m->name, h->theatre->name, s->row+1, s->col+1, h->price);
            printf("*********************\n");
            goto SEL_M;                 // goto start
        } else {                        // cancel
            goto SEL_S;
        }
    }

    return ;
}

