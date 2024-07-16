#include <stdio.h>
#include <string.h>

#include "listhandler.h"

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

void loadFromFile(todoList *list, const char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp != NULL) {
    list->count = 0;
    while (fscanf(fp, "%d, %[^\n]\n", &list->items[list->count].completed,
                  list->items[list->count].task) == 2) {
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
    list->items[list->count].completed = 0;
    list->count++;
  }
}

void deleteItem(todoList *list, int index) {
  if (index < 0 || index >= list->count) {
    perror("Invalid index");
    return;
  } else {
    for (int i = 0; i < list->count - 1; ++i) {
      strcpy(list->items[i].task, list->items[i + 1].task);
      list->items[i].completed = list->items[i + 1].completed;
    }
    list->count--;
  }
}

void markCompleted(todoList *list, int index) {
  if (index < 0 || index >= list->count) {
    perror("Invalid index.\n");
    return;
  } else {
    list->items[index].completed = 1;
  }
}

void printList(todoList *list) {
  for(int i = 0; i < list->count; ++i) {
    printf("%d. [%c] %s\n", i + 1, (list->items[i].completed ? 'x' : ' '), list->items[i].task);
  }
}
