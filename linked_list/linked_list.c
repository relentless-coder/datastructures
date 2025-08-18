#include <stdlib.h>

#include "../node/node.h"
#include "linked_list.h"

linked_list_t *create_new_linked_list() {
  linked_list_t *new_list = malloc(sizeof(linked_list_t));
  if (new_list == NULL) {
    return NULL;
  }

  new_list->head = NULL;
  new_list->tail = NULL;
  new_list->length = 0;

  return new_list;
}

void remove_head(linked_list_t *list) {
  if (list == NULL || list->head == NULL) {
    return;
  }
  list_node_t *next_head = list->head->next;
  node_t *tmp_node = list->head->node;
  list_node_t *tmp_head = list->head;
  list->head = next_head;
  --list->length;
  if (list->length == 0) {
    list->tail = NULL;
  }
  free_node(tmp_node);
  free(tmp_head);
}

void add_node(linked_list_t *list, node_t *node) {
  if (list == NULL || node == NULL) {
    return;
  }
  list_node_t *new_list_node = malloc(sizeof(list_node_t));
  if (new_list_node == NULL) {
    return;
  }
  new_list_node->node = node;
  new_list_node->next = NULL;
  if (list->length == 0) {
    list->tail = new_list_node;
    list->head = new_list_node;
  } else {
    list->tail->next = new_list_node;
    list->tail = new_list_node;
  }
  ++list->length;
  return;
}

void purge_list(linked_list_t *list) {
  if (list == NULL) {
    return;
  }

  while (list->head) {
    remove_head(list);
  }

  free(list);
}

list_node_t* get_head(linked_list_t* list, list_node_data_t) {
  if (list == NULL) {
    return NULL;
  }
}
