/**************************************
 * roflcopter.c
 *
 * Lets watch a sweet roflcopter fly.
 *
 * Author:  Justin Helgesen
 *          justinhelgesen@gmail.com
 * Created: 9/4/2016
 *
 * The MIT License (MIT)
 * Copyright (c) 2016 Justin Helgesen
 * 
 **************************************/

#include <curses.h>
#include <signal.h>
#include <unistd.h>
#include "roflcopter.h"

int main(int argc, char *argv[])
{
    initscr();
    signal(SIGINT, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);

    static char *frames[2][ROFLHEIGHT] =
        {{ ROFL00, ROFL01, ROFL02, ROFL03, ROFL04, ROFL05, ROFL06 },
         { ROFL10, ROFL11, ROFL12, ROFL13, ROFL14, ROFL15, ROFL16 }};

    int x = 0;
    int rofl_length = ROFLLENGTH;
    int rofl_center = LINES / 2 - ROFLHEIGHT / 2;
    for (int i = 0; x < COLS; i++, x+=3) {
        if (x + ROFLLENGTH > COLS) {
            rofl_length = (ROFLLENGTH + COLS) - (x + ROFLLENGTH);
        } else {
            rofl_length = ROFLLENGTH;
        }
        for (int y = 0; y < ROFLHEIGHT; y++) {
            mvaddnstr(rofl_center + y, x, frames[i%2][y], rofl_length);
        }
        getch();
        refresh();
        usleep(125000);
        for (int y = 0; y < ROFLHEIGHT; y++) {
            mvaddstr(rofl_center + y, x, ROFLDEL);
        }
    }
    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();
}
