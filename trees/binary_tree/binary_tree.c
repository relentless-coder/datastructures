#include <stdlib.h>

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
  new_tree->size = 1;
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
  ++tree->size;
}

binary_tree_node_t *
compare_and_return_smaller_binary_tree_node(binary_tree_node_t *a,
                                            binary_tree_node_t *b) {
  if (a == NULL || b == NULL) {
    return NULL;
  }
  const node_t *smaller_node =
      compare_and_return_smaller_node(a->node, b->node);
  if (smaller_node == NULL) {
    return NULL;
  }
  if (smaller_node == a->node) {
    return a;
  }
  return b;
}

void find_parent_and_add_node_to_it(binary_tree_node_t *root_node,
                                    binary_tree_node_t *node_to_add) {
  if (root_node == NULL || node_to_add == NULL) {
    return;
  }
  const binary_tree_node_t *smaller_node =
      compare_and_return_smaller_binary_tree_node(root_node, node_to_add);
  if (smaller_node == NULL) {
    return;
  }
  if (smaller_node == node_to_add && root_node->left != NULL) {
    find_parent_and_add_node_to_it(root_node->left, node_to_add);
  }

  if (smaller_node == root_node && root_node->right != NULL) {
    find_parent_and_add_node_to_it(root_node->right, node_to_add);
  }

  if (smaller_node == node_to_add) {
    root_node->left = node_to_add;
  } else {
    root_node->right = node_to_add;
  }
}

node_t **collect_nodes_from_tree(binary_tree_t *tree) {
  if (tree == NULL || tree->root == NULL) {
    return NULL;
  }
  node_t **nodes_list = calloc(tree->size, sizeof(node_t *));
  if (nodes_list == NULL) {
    return NULL;
  }
  size_t pos = 0;
  inorder_traversal(nodes_list, tree->root, &pos);
  return nodes_list;
}

void inorder_traversal(node_t **node_list, binary_tree_node_t *root,
                       size_t *pos) {
  if (root == NULL) {
    return;
  }
  inorder_traversal(node_list, root->left, pos);
  node_list[*(pos)] = root->node;
  *pos += 1;
  inorder_traversal(node_list, root->right, pos);
}
