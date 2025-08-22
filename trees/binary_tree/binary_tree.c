#include <stdlib.h>

#include "../../node/node.h"
#include "binary_tree.h"

binary_tree_t *create_new_binary_tree(binary_tree_node_t *tree_node) {
  if (tree_node == NULL) {
    return NULL;
  }
  binary_tree_t *new_tree = malloc(sizeof(binary_tree_t));
  if (new_tree == NULL) {
    return NULL;
  }
  new_tree->root = tree_node;
  return new_tree;
}

void add_node_to_binary_tree(binary_tree_t *tree,
                             binary_tree_node_t *tree_node) {
  if (tree == NULL || tree_node == NULL) {
    return;
  }
  binary_tree_node_t *root = tree->root;
  if (root == NULL) {
    tree->root = tree_node;
    return;
  }
  find_parent_and_add_node_to_it(root, tree_node);
  return;
}

binary_tree_node_t *
compare_and_return_smaller_binary_tree_node(binary_tree_node_t *a,
                                            binary_tree_node_t *b) {
  node_t *smaller_node = compare_and_return_smaller_node(a->node, b->node);
  if (smaller_node == a->node) {
    return a;
  }
  return b;
}

// Yes I'm building a binary search tree
void
find_parent_add_add_node_to_it(binary_tree_node_t *root_node,
                               binary_tree_node_t *node_to_add) {
  binary_tree_node_t *smaller_node =
      compare_and_return_smaller_binary_tree_node(root_node, node_to_add);
  if (smaller_node == node_to_add && root_node->left != NULL) {
    find_parent_add_add_node_to_it(root_node->left, node_to_add);
  }

  if (smaller_node == root_node && root_node->right != NULL) {
    find_parent_and_add_node_to_it(root_node->right, node_to_add);
  }

  if (smaller_node == node_to_add) {
    root_node->left = node_to_add;
  } else {
    root_node->right = node_to_add;
  }
  return;
}
