typedef struct TreeNode tree_node_t;

typedef struct Tree {
  tree_node_t* root;
  int size;
} tree_t;

tree_t* create_new_tree(tree_node_t* root);
void add_tree_node_to_tree(tree_t* tree, tree_node_t* target_node, tree_node_t* node_to_add);
void remove_tree_node_from_tree(tree_t* tree, tree_node_t* node_to_remove);
