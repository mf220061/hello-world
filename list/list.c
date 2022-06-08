#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct element {
  int value;
  struct element* next;
  struct element* prev;
};

struct list {
  int n;
  struct element* head;
  struct element* tail;
};

struct list* create_list(struct list* list, struct element* node) {
  list->head = node;
  list->tail = node;
  return list;
}

struct list* tail_add(struct list* list, int value) {
  struct element* node = (struct element*)malloc(sizeof(struct element));
  node->value = value;
  node->next = NULL;
  list->n++;
  if (list->head == NULL) {
    return create_list(list, node);
  } else {
    struct element* p = list->tail;
    p->next = node;
    node->prev = p;
    list->tail = node;
    return list;
  }
}

struct list* head_add(struct list* list, int value) {
  struct element* node = (struct element*)malloc(sizeof(struct element));
  node->value = value;
  node->prev = NULL;
  list->n++;
  if (list->head == NULL) {
    return create_list(list, node);
  } else {
    struct element* p = list->head;
    p->prev = node;
    node->next = p;
    list->head = node;
    return list;
  }
}

struct list* delete(struct list* list, int position) {
  if (position >= list->n || position < 0) {
    return list;
  }
  struct element* p = list->head;
  for (int i = 0; i < position; i++) {
    p = p->next;
  }
  struct element* q = p->next;
  q->prev = p->prev;
  p->prev->next = q;
  free(p);
}

struct list* insert(struct list* list, int position) {
  if (position >= list->n || position < 0) {
    return list;
  }
}

void show(struct list* list) {
  struct element* p = list->head;
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
  struct list* list = (struct list*)malloc(sizeof(struct list));
  list->n = 0;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    if (rand() % 2 == 0) {
      list = tail_add(list, get_random(0, 9));
    } else {
      list = head_add(list, get_random(0, 9));
    }
    show(list);
  }
  show(list);
  delete(list, 1);
  show(list);
  return 0;
}
