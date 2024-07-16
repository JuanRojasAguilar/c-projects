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
void loadFromFile(todoList *list, const char *filename);
void addItem(todoList *list, const char *task);
void deleteItem(todoList *list, int index);
void markCompleted(todoList *list, int index);
