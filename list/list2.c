#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct element {
  int value;
  struct element* next;
};

struct list {
  int n;
  struct element* head;
  struct element* tail;
};

struct list* create_list(struct list* list, struct element* node) {
  list->head = node;
  list->tail = node;
  node->next = NULL;
  list->n = 1;
  return list;
}

struct list* tail_add(struct list* list, struct element* node) {
  if (list->head == NULL) return create_list(list, node);
  else {
    struct element* p = list->tail;
    p->next = node;
    list->tail = node;
    node->next = NULL;
    list->n++;
    return list;
  }
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

struct list* insert(struct list* list, int position, struct element* node) {
  if (position < 0 || position > list->n) return list;
  else if (position == 0) {
    if (list->head == NULL) return create_list(list, node);
    struct element* p = list->head;
    node->next = list->head;
    list->head = node;
    list->n++;
    return list;
  }
  struct element* p = list->head;
  while (true)
    if (p != list->tail && position != 1) {
      p = p->next;
      position--;
    } else break;
  if (p == list->tail) return tail_add(list, node);
  struct element* q = p->next;
  p->next = node;
  node->next = q;
  list->n++;
  return list;
}

struct list* insert_sort(struct list* oldlist) {
  struct list* newlist = (struct list*)malloc(sizeof(struct list));
  struct element* oldp = oldlist->head;
  oldlist->head = oldp->next;
  newlist = insert(newlist, 0, oldp);
  struct element* newp = newlist->head;
  oldlist->n--;
  while (true) {
    if (oldlist->n == 0) break;
    int position = 0;
    while (true) {
      if (newp->value > oldp->value) {
        if (oldp == oldlist->head) {
          if (oldp == oldlist->tail) {
            newlist = insert(newlist, position, oldp);
            return newlist;
          }
          oldlist->head = oldp->next;
        }
        newlist = insert(newlist, position, oldp);
        oldlist->n--;
        break;
      }
      if (newp == newlist->tail) {
        if (oldp == oldlist->head) {
          if (oldp == oldlist->tail) {
            newlist = insert(newlist, newlist->n, oldp);
            return newlist;
          }
          oldlist->head = oldp->next;
        }
        newlist = insert(newlist, newlist->n, oldp);
        break;
      }
      newp = newp->next;
      position++;
    }
    newp = newlist->head;
    oldp = oldlist->head;
  }
  return newlist;
}

int get_random(int min, int max) { return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX)); }

int main(void) {
  struct element* node = NULL;
  struct list* list = (struct list*)malloc(sizeof(struct list));
  list->n = 0;
  int num = 0;

  //srand((unsigned int)time(NULL));
  srand(1);
  for (int i = 0; i < 10000; i++) {
    num = get_random(0, 9999);
    struct element* node = (struct element*)malloc(sizeof(struct element));
    node->value = num;
    list = tail_add(list, node);
  }
  show(list);
  printf("\n");
  clock_t start = clock();
  list = insert_sort(list);
  clock_t end = clock();
  show(list);
  printf("time: %.3fms\n", (double)(end - start) / 1000);
  return 0;
}
