#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

struct element {
  int value;
  bool head, tail;
  struct element* next;
  struct element* prev;
};

struct element* add(struct element* list, int value) {
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

struct element* insert_sort(struct element* input) {
  struct element* output = (struct element*)malloc(sizeof(struct element));
  while (!input->head) {
    input = input->prev;
  }
  output->value = input->value;
  output->tail, output->head = true, true;
  while (!input->tail) {
    while (!output->tail) {
    }
  }
  return output;
}

void show(struct element* list) {
  struct element* p = list;
  while (!p->tail) {
    printf("%d ", p->value);
    p = p->next;
  }
  printf("\n");
  return;
}

int GetRandom(int min, int max) {
  return min + (int)(rand() * (max - min + 1.0) / (1.0 + RAND_MAX));
}

int main(void) {
  struct element* list = NULL;
  srand((unsigned int)time(NULL));
  for (int i = 0; i < 10; i++) {
    list = add(list, GetRandom(0, 9));
    show(list);
  }
  show(list);
  return 0;
}
