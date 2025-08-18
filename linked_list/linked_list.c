#include <stdlib.h>

#include "linked_list.h"
#include "../node/node.h"

linked_list_t* create_new_linked_list() {
  linked_list_t *new_list = malloc(sizeof(linked_list_t));
  if (new_list == NULL) {
    return NULL;
  }

  new_list -> head = NULL;
  new_list -> tail = NULL;
  new_list -> length = 0;

  return new_list;
}


void remove_head(linked_list_t* list) {
  list_node_t* next_head = list->head ->next;
  free_node(list -> head -> node);
  free(list -> head);
  if (--list -> length == 0) {
    list -> tail = NULL;
    list -> head = NULL;
  }

  list -> head = next_head;
}

void add_node(linked_list_t* list, node_t* node) {

  list_node_t* new_list_node = malloc(sizeof(list_node_t));
  if (new_list_node == NULL) {
    return;
  }
  new_list_node -> node = node;
  new_list_node -> next = NULL;
  return ;
}
