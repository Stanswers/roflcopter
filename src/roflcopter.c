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
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <roflcopter/roflcopter.h>

void play_roflcopter(const int refresh_rate, const int movement_increment)
{
    static char *frames[2][ROFLHEIGHT] =
        {{ ROFL00, ROFL01, ROFL02, ROFL03, ROFL04, ROFL05, ROFL06 },
         { ROFL10, ROFL11, ROFL12, ROFL13, ROFL14, ROFL15, ROFL16 }};
    int rofl_length;
    int rofl_center = LINES / 2 - ROFLHEIGHT / 2;
    for (int i = 0, x = 0; x < COLS; i++, x+=movement_increment) {
        rofl_length = x + ROFLLENGTH < COLS ? ROFLLENGTH : COLS - x;
        for (int y = 0; y < ROFLHEIGHT; y++) {
            mvaddnstr(rofl_center + y, x, frames[i%2][y], rofl_length);
        }
        getch();
        refresh();
        usleep(refresh_rate);
        for (int y = 0; y < ROFLHEIGHT; y++) {
            mvaddnstr(rofl_center + y, x, ROFLDEL, rofl_length);
        }
    }
}

void print_help() {
    printf("Usage: roflcopter [OPTION]\n");
    printf("Watch a pretty roflcopter air show\n");
    printf("  -e, --evil             Run Evil Mode\n");
    printf("  -f, --fast             Fly faster\n");
    printf("  -h, --help             Print this help menu\n");
}

int main(int argc, char *argv[])
{
    bool is_evil = false;
    int movement_increment=3;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0 ||
            strcmp(argv[i], "--evil") == 0) {
            is_evil = true;
        } else if (strcmp(argv[i], "-f") == 0 ||
                   strcmp(argv[i], "--fast") == 0) {
            movement_increment=9;
        } else if (strcmp(argv[i], "-h") == 0 ||
                   strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else {
            printf("roflcopter: invalid option -- '%s'\n", argv[i]);
            printf("Try 'roflcopter --help' for more information\n");
            return 1;
        }
    }
    initscr();
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    leaveok(stdscr, TRUE);
    scrollok(stdscr, FALSE);
    do {
        play_roflcopter(125000, movement_increment);
    } while (is_evil);
    mvcur(0, COLS - 1, LINES - 1, 0);
    endwin();
}
