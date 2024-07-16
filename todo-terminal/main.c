#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>
#include <string.h>

#define maxItems 100
#define maxLength 50

typedef struct {
  char task[maxLength];
  int completed;
} todoItem;

typedef struct {
  todoItem items[maxItems];
  int count;
} todoList;

void saveToFile(todoList *list, const char *filename);
void loadToFile(todoList *list, const char *filename);
void addItem(todoList *list, const char *task);
void deleteItem(todoList *list, int index);

int main(void) {
  initscr();
  cbreak();
  noecho();
  keypad(stdscr, TRUE);
  endwin();
  return 0;
}

void saveToFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "w");
  if (fp != NULL) {
    for (int i = 0; i < list->count; i++) {
      fprintf(fp, "%d, %s\n", list->items[i].completed, list->items[i].task);
    }
  } else {
    perror("Error Opening file");
    return;
  }
  fclose(fp);
}

void loadToFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp != NULL) {
    list->count = 0;
    while (fscanf(fp, "%d, %[^\n]\n", &list->items[list->count].completed, list->items[list->count].task) == 2) {
      list->count++;
      if (list->count >= maxItems) {
        break;
      }
    }
  } else {
    perror("Error opening file");
    return;
  }
  fclose(fp);
}

void addItem(todoList *list, const char *task) {
  if (list->count >= maxItems) {
    printf("Max capacity of %i, complete some\n", maxItems);
    return;
  } else {
    strcpy(list->items[list->count].task, task);
    list->count++;
  }
}

void deleteItem(todoList *list, int index) {
  if (index < 0) {

  } else {
    
    list->count--;
  }
}

