#include <ncurses.h>
#include <unistd.h>
#include <time.h> // testing

#define DELAY 42000
#define MAX_PLAYER_LENGTH 20

void change_position(int positions[][2], int player_l, int new_y, int new_x);

int main() {
  int x, y;
  int max_x, max_y;
  int next_x = 0, next_y = 0;
  int direction = 1;
  int playerPosition[MAX_PLAYER_LENGTH][2] = {{x, y}}; 
  int player_length = 1;
  time_t start_time, current_time; //testing
  
  
  int key;

  initscr();
  noecho();
  curs_set(FALSE);
  keypad(stdscr, TRUE);
  
  getmaxyx(stdscr, max_y, max_x);
  time(&start_time);
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
        change_position(playerPosition, player_length, y, x);
        break;
      case 2:
        if ((y + 1) == max_y - 1) {
          y = 0;
        } else {
          y = y + 1;
        }
        change_position(playerPosition, player_length, y, x);
        break;
      case 3:
        if ((x - 2) <= 0) {
          x = max_x;
        } else {
          x = x - 2;
        }
        change_position(playerPosition, player_length, y, x);
        break;
      case 4:
        if ((x + 2) == max_x - 2) {
          x = 0;
        } else {
          x = x + 2;
        }
        change_position(playerPosition, player_length, y, x);
        break;
      default:
        break;
    }

    // testing sec

    time(&current_time);
    if (difftime(current_time, start_time) >= 2.0) {
      player_length++;
      time(&start_time);
    }

    clear();
    for (int i = 0; i < player_length; i++) {
      mvprintw(playerPosition[i][0], playerPosition[i][1], "P");
    }
    refresh();
    usleep(DELAY);
  }

  endwin();
  return 0;
}

void change_position(int positions[][2], int player_l, int new_y, int new_x) {
  positions[player_l - 1][0] = new_y;
  positions[player_l - 1][1] = new_x;
  if (player_l > 1) {
    for (int i = 0; i < player_l; ++i) {
      positions[i][0] = positions[i + 1][0];
      positions[i][1] = positions[i + 1][1];
    }
  }
}
