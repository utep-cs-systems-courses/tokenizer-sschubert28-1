#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

List* init_history() {
  List *word_history = (List*) malloc(sizeof(Item)*100);
}

void add_history(List *list, char *str) {
  Item *node = list->root;

  if (node == NULL) {
    node = (Item*) malloc(sizeof(Item));
    node->id = 1;
    node->str = str;
    node->next = NULL;
    list->root = node;
    printf("%s\n",node->next->str);
    printf("%i\n",node->next->id);
  } else {
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = (Item*) malloc(sizeof(Item));
    node->next->id = node->id +1;
    node->next->str = str;
    node->next->next = NULL;
    printf("%s\n",node->next->str);
    printf("%i\n",node->next->id);
  }
}

char *get_history(List *list, int id) {
  Item *node = list->root;

  while (node != NULL) {
    if (node->id == id) {
      return node->str;
    }
    node = node->next;
  }
  return NULL;
}

void print_history(List *list) {
  Item *node = list->root;
  while (node != NULL) {
    printf("%s\n", node->str);
    node = node->next;
  }
}

void free_history(List *list) {
  Item *node = list->root;
  while (node != NULL) {
    free(node);
    node = node->next;
  }
  free(list);
}
