typedef struct Node node_t;
typedef struct BinaryTreeNode binary_tree_node_t;
typedef struct TreeNode tree_node_t;

typedef struct TreeNode {
  node_t* node;
  tree_node_t* first_child;
  tree_node_t* next_sibling;
} tree_node_t;


tree_node_t* create_new_tree_node(node_t* node);
void free_tree_node(tree_node_t* tree_node);

