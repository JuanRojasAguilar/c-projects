#include <ncurses.h>

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
  int chosenIndex;
  char newTask[maxLength];

  do {
    clear();
    printw("-> Manage your tasks <-\n");
    printw(".......................\n");
    for (int i = 0; i < todolist.count; ++i) {
      printw("%d. [%c] %s\n", i + 1, (todolist.items[i].completed ? 'x' : ' '), todolist.items[i].task);
    }
    printw("\n\n");
    printw("1-> Add new tasks. \n");
    printw("2-> Mark as completed. \n");
    printw("3-> Delete item. \n");
    printw("4-> Save and quit. \n");
    printw("\nEnter your choice pookie: ");
    refresh();

    echo();
    scanw("%d", &choice);
    refresh();

    switch (choice) {
      case 1:
        clear();
        printw("Add new task: ");
        refresh();
        echo();
        getstr(newTask);
        noecho();
        addItem(&todolist, newTask);
        break;
      case 2:
        clear();
        printw("Enter the index of item completed: ");
        refresh();
        scanw("%d", &chosenIndex);
        noecho();
        markCompleted(&todolist, chosenIndex - 1);
        break;
      case 3:
        clear();
        printw("Enter item index to be deleted: ");
        refresh();
        scanw("%d", &chosenIndex);
        deleteItem(&todolist, chosenIndex - 1);
        break;
      case 4:
        saveToFile(&todolist, fileName);
        break;
      default:
        printw("Invalid choice\n");
        break;
    }
    refresh();
  } while (choice != 4);

  endwin();
  return 0;
}


