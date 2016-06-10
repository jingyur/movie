struct hall;
struct movie;
struct seat;

void do_run(movie* list);

movie* io_sel_movie(movie* list);
hall* io_sel_hall(movie* m);
seat* io_sel_seat(hall* h);
bool io_confirm_seat(hall* h, seat* s);
