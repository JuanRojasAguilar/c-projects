#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000
#define MAX_PLAYER_LENGTH 20

void printPlayer(char *player);

int main() {
  int x, y;
  int max_x, max_y;
  int next_x = 0, next_y = 0;
  int direction = 1;
  char player[MAX_PLAYER_LENGTH] = {'P'};
  
  int key;

  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  
  getmaxyx(stdscr, max_y, max_x);
  x = max_x >> 1;
  y = max_y >> 1;
  printw("Use arrow keys to move, 'q' to exit\n");

  while(1) {
    timeout(0);
    key = getch();
  
    switch (key) {
      case KEY_UP:
        direction = 1;
        break;
      case KEY_DOWN:
        direction = 2;
        break;
      case KEY_LEFT:
        direction = 3;
        break;
      case KEY_RIGHT:
        direction = 4;
        break;
      case 'q':
        endwin();
        return 0;
      default:
        break;
    }

    switch(direction) {
      case 1:
        if ((y - 1) <= 0) {
          y = max_y;
        } else {
          y = y - 1;
        }
        break;
      case 2:
        if ((y + 1) == max_y - 1) {
          y = 0;
        } else {
          y = y + 1;
        }
        break;
      case 3:
        if ((x - 1) <= 0) {
          x = max_x;
        } else {
          x = x - 1;
        }
        break;
      case 4:
        if ((x + 1) == max_x - 1) {
          x = 0;
        } else {
          x = x + 1;
        }
        break;
      default:
        break;
    }

    clear();
    mvprintw(y, x, "P");
    refresh();
    usleep(DELAY);
  }

  endwin();
  return 0;
}


