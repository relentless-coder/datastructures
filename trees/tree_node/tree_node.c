#include <stdlib.h>

#include "tree_node.h"
#include "../../node/node.h"


tree_node_t* create_new_tree_node(node_t* node) {
  if (node == NULL) {
    return NULL;
  }
  tree_node_t* new_tree_node = malloc(sizeof(tree_node_t));
  if (new_tree_node == NULL) {
    return NULL;
  } 
  new_tree_node ->node = node;
  new_tree_node ->first_child = NULL;
  new_tree_node ->next_sibling = NULL;
  return new_tree_node;
}

void free_tree_node(tree_node_t* tree_node) {
  if (tree_node == NULL) {
    return;
  }
  free_node(tree_node ->node);
  if (tree_node ->first_child != NULL) {
    free_tree_node(tree_node -> first_child);
  }
  if (tree_node -> next_sibling != NULL) {
    free_tree_node(tree_node ->next_sibling);
  }
  return;
}
