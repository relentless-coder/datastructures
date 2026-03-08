#include <stdio.h>
#include "../../node/node.h"
#include "../../hashmap/hashmap.h"

typedef struct Node node_t;
typedef struct TrieNode trie_node_t;
typedef struct Trie trie;

typedef struct TrieNode {
  node_t* node;
  int is_word;
  hash_map* children;
} trie_node_t;

typedef struct Trie {
  trie_node_t *root;
  size_t size;
} trie;

trie_node_t* create_tree_node(node_t* node, int is_word);
trie* create_trie();
void add_string_to_trie(trie_node_t* tree_root, char* string);
int check_word_exists(trie_node_t* root, char* word);
char** search(trie_node_t* root, char* search_input);
