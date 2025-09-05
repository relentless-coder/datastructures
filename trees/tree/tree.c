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
  new_tree->size = 1;
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
    target_node->next_sibling = node_to_add;
  }
  return;
}

int remove_tree_node_from_tree(tree_node_t *root, tree_node_t *node_to_remove) {
  if (root == NULL || node_to_remove == NULL) {
    return 0;
  }
  if (root == node_to_remove) {
    free_tree_node(root);
    return 1;
  }
  int res = remove_tree_node_from_tree(root->first_child, node_to_remove);
  if (res == 1) {
    return res;
  }
  return remove_tree_node_from_tree(root->next_sibling, node_to_remove);
}
