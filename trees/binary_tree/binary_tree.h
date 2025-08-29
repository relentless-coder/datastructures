#include <stdio.h>
#include "../../node/node.h"

typedef struct BinaryTreeNode binary_tree_node_t;

typedef struct BinaryTree binary_tree_t;

typedef struct BinaryTreeNode {
  node_t* node;
  binary_tree_node_t* left;
  binary_tree_node_t* right;
} binary_tree_node_t;


typedef struct BinaryTree {
  binary_tree_node_t* root;
  int size;
} binary_tree_t;

binary_tree_t* create_new_binary_tree(binary_tree_node_t* tree_node);
void add_node_to_binary_tree(binary_tree_t* tree, binary_tree_node_t* tree_node);
void free_binary_tree_node(binary_tree_t* tree, binary_tree_node_t* tree_node);
void find_parent_and_add_node_to_it(binary_tree_node_t* root_node, binary_tree_node_t* node_to_add);
binary_tree_node_t* compare_and_return_smaller_binary_tree_node(binary_tree_node_t* a, binary_tree_node_t* b);
node_t** collect_nodes_from_tree(binary_tree_t* tree);
void inorder_traversal(node_t** node_list, binary_tree_node_t* root, size_t* pos);
