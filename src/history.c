#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tokenizer.h"
#include "history.h"

List* init_history() {
  List *word_history = (List*) malloc(sizeof(List)*100);
  word_history->root = NULL;
  return word_history;
}

void add_history(List *list, char *str) {
  Item *node = (Item*) malloc(sizeof(Item));
  node->str = copy_str(str, strlen(str));
  node->next = NULL;

  if (list->root == NULL) {
    list->root = node;
    node->id = 1;
  } else {
    Item *head = list->root;
    while(head->next != NULL) {
      head = head->next;
    }
    node->id = (head->id) + 1;
    head->next = node;
  }
}
  
  /*
  if (node == NULL) {
    printf("node is null\n");
    node = (Item*) malloc(sizeof(Item));
    node->id = 1;
    node->str = str;
    node->next = NULL;
    list->root = node;
    printf("%s\n",node->next->str);
    printf("%i\n",node->next->id);
  } else {
    printf("node is not null\n");
    while (node->next != NULL) {
      node = node->next;
    }
    node->next = (Item*) malloc(sizeof(Item));
    node->next->id = node->id + 1;
    node->next->str = str;
    node->next->next = NULL;
    printf("%s\n",node->next->str);
    printf("%i\n",node->next->id);
  }
}
  */

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
  if(node == NULL) {
    printf("History is empty\n");
    return;
  }
  while (node != NULL) {
    printf("[%d] %s\n",node->id, node->str);
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
