#include <stdlib.h>

#include "../tree_node/tree_node.h"
#include "tree.h"

tree_t *create_new_tree(tree_node_t *root) {
  if (root == NULL) {
    return NULL;
  }
  tree_t *new_tree = malloc(sizeof(tree_t));
  if (new_tree == NULL) {
    return NULL;
  }
  new_tree->root = root;
  ++new_tree->size;
  return new_tree;
}

void add_tree_node_to_tree(tree_t *tree, tree_node_t *target_node,
                              tree_node_t *node_to_add) {
  if (tree == NULL || target_node == NULL || node_to_add == NULL) {
    return;
  }

  if (target_node->first_child == NULL) {
    target_node->first_child = node_to_add;
  } else {
    add_tree_node_to_tree(tree, target_node->next_sibling, node_to_add);
    target_node -> next_sibling = node_to_add;
  }
  return;
}

void remove_tree_node_from_tree(tree_t* tree, tree_node_t* node_to_remove) {
  if (tree == NULL || node_to_remove == NULL) {
    return;
  }
  tree_node_t* l_root = tree -> root;
  if (l_root == NULL) {
    return;
  }
  while (l_root != NULL)
  if (l_root ->first_child == node_to_remove) {
    free_tree_node(l_root -> first_child);
  }
}
