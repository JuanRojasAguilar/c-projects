#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#include "listhandler.h"

int main(void) {
  todoList todolist;
  todolist.count = 0;

  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);

  char fileName[] = "tasks.txt";
  loadFromFile(&todolist, fileName);

  int choice;
  char newTask[maxLength];

  do {
    clear();
    printw("-> Manage your tasks <-\n");
    printw(".......................\n");
    for (int i = 0; i < todolist.count; ++i) {
      printw("%d. [%c] %s\n", i + 1, (todolist.items[i].completed ? 'x' : ' '));
    }
    printw("\n\n");
    printw("1-> Add new tasks. \n");
    printw("2-> Mark as completed. \n");
    printw("3-> Delete item. \n");
    printw("4-> Save and quit. \n");
    printw("\nEnter your choice pookie: ");
    refresh();

    switch (choice) {
      case 1:
        clear();
        break;
      case 2:
        clear();
        break;
      case 3:
        clear();
        break;
      case 4:
        clear();
        break;

    }
  } while (choice != 4);

  endwin();
  return 0;
}


