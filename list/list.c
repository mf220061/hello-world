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

struct list* tail_add(struct list* lst, int value) {
  struct element* node = (struct element*)malloc(sizeof(struct element));
  node->value = value;
  node->next = NULL;
  lst->n++;
  if (lst->head == NULL) {
    lst->head = node;
    lst->tail = node;
    return lst;
  } else {
    struct element* p = lst->tail;
    p->next = node;
    node->prev = p;
    lst->tail = node;
    return lst;
  }
}

void show(struct list* lst) {
  struct element* p = lst->head;
  while (p->next != NULL) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");
  return;
}

int get_random(int min, int max) {
  return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

int main(void) {
  struct element* node = NULL;
  struct list* lst = (struct list*)malloc(sizeof(struct list));
  lst->n = 0;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    lst = tail_add(lst, get_random(0, 9));
    show(lst);
  }
  show(lst);
  return 0;
}
