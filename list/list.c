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
  list->n--;
  return list;
}

struct list* insert(struct list* list, int position, int value) {
  if (position > list->n || position < 0) {
    return list;
  } else if (position == 0) {
    return head_add(list, value);
  } else if (position == list->n) {
    return tail_add(list, value);
  }
  struct element* p = list->head;
  list->n++;
  while (position > 1) {
    p = p->next;
    position--;
  }
  struct element* node = (struct element*)malloc(sizeof(struct element));
  node->value = value;
  struct element* q = p->next;
  q->prev = node;
  node->next = q;
  p->next = node;
  node->prev = p;
  return list;
}

struct list* insert_sort(struct list* list) {
  struct list* newlist = (struct list*)malloc(sizeof(struct list));
  int count = list->n - 1;
  struct element* p = list->head;
  newlist = insert(newlist, p, 0);
  struct element* q = newlist->head;
  for (int i = 0; i < count; i++) {
    for (int j = 0; j < newlist->n; j++) {
      if (p->value < q->value || q == newlist->tail) {
        newlist = insert_element(newlist, p, j);
        break;
      }
      q = q->next;
    }
    /*do {
      if (p->value 
    } while (q == newlist->tail);*/
    q = newlist->head; 
  }
  free(list);
  return newlist;
}

void show(struct list* list) {
  struct element* p = list->head;
  while (true) {
    printf("%d ", p->value);
    if (p != list->tail) p = p->next;
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
    if (rand() % 2 == 0) {
      list = tail_add(list, num);
    } else {
      list = head_add(list, num);
    }
    show(list);
  }
  show(list);
  list = delete(list, list->n - 1);
  show(list);
  list = delete(list, 0);
  show(list);
  list = delete(list, 1);
  show(list);
  list = delete(list, 1);
  show(list);
  printf("%d\n", list->n);
  list = insert(list, list->n, 10);
  show(list);
  list = insert(list, 0, 100);
  show(list);
  list = insert(list, 1, 1000);
  show(list);
  return 0;
}
