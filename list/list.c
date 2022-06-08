#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct element {
  int value, id;
  struct element* next;
  struct element* prev;
};

struct list {
  int n;
  struct element* head;
  struct element* tail;
};

struct list* add(struct list* list, int value) {
  struct element* node = (struct element*)malloc(sizeof(struct element));
  node->value = value;
  node->next = NULL;
  if (list == NULL) {
    node->head, node->tail = true, true;
    return node;
  } else {
    struct element* p = list;
    while (!p->tail) {
      p = p->next;
    }
    p->next = node;
    p->tail = false;
    node->tail = true;
    return list;
  }
}

int GetRandom(int min, int max) {
  return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

int main(void) {
  struct element* node = NULL;
  struct list* list = NULL;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    list = add(list, GetRandom(0, 9));
    show(list);
  }
  show(list);
  return 0;
}
