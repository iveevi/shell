#include "system.h"

// Import global system variables
__uint8_t status = NORMAL;

int main()
{
    int ses_len = 100;
    char *input;
    int c;
    initscr();
    noecho();
    keypad(stdscr, TRUE);
    printw("Keep entering characters!\n");
    while (ses_len--) {
        c = getch();
        if (c == KEY_BACKSPACE || c == KEY_DC) {
            printw("\b \b");
            refresh();
        } else {
            addch(c);
        }
    }
    endwin();
}
