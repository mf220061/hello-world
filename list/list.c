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
  if (p->next != NULL && p->prev != NULL) {
    struct element* q = p->next;
    q->prev = p->prev;
    p->prev->next = q;
  } else if (p->next == NULL) {
    list->tail = p->prev;
  } else {
    list->head = p->next;
  }
  free(p);
}

struct list* insert(struct list* list, int position) {
  if (position >= list->n || position < 0) {
    return list;
  }
}

void show(struct list* list) {
  struct element* p = list->head;
  while (true) {
    printf("%d ", p->value);
    if (p->next != NULL) p = p->next;
    else break;
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
  int num = 0;

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    num = get_random(0, 9);
    printf("%d ", num);
    if (rand() % 2 == 0) {
      printf("tail\n");
      list = tail_add(list, num);
    } else {
      printf("head\n");
      list = head_add(list, num);
    }
    show(list);
    printf("\n");
  }
  show(list);
  printf("\n");
  /*
  delete(list, list->n - 1);
  show(list);
  delete(list, 0);
  show(list);
  delete(list, 1);
  show(list);
  */ // deleteの動作確認
  return 0;
}
