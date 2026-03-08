#include "string.h"
#include "stdlib.h"
#include "./trie.h"

trie_node_t* create_trie_node(node_t* node, int is_word) {
  if (node == NULL) {
    return NULL;
  }
  trie_node_t* trie_node = malloc(sizeof(trie_node_t));
  if (trie_node == NULL) {
    return NULL;
  }
  trie_node->node = node;
  trie_node->is_word = is_word;
  trie_node->children = NULL;
  return trie_node;
}

trie* create_trie() {
  trie_node_t* tree_node = create_trie_node(NULL, 0);
  if (tree_node) {
    return NULL;
  }
  trie* new_trie = malloc(sizeof(trie));
  if (new_trie == NULL) {
    return NULL;
  }
  new_trie ->root = tree_node;
  new_trie -> size = 0;
  return new_trie;
}

void add_string_to_trie(trie_node_t* tree_root, char* string) {
  if (tree_root == NULL || string == NULL) {
    return;
  }
  size_t str_len = strlen(string);
  if (str_len == 0) {
    return;
  }
  trie_node_t* prev = tree_root;
  for (size_t i = 0; i < str_len; i++) {
    char hus = string[i];
    data_object* curr = get_data_object_for_key(prev->children, &hus);
    if (curr != NULL) {
      prev = (trie_node_t*)curr->value;
      continue;
    } else {
      node_t* new_node = create_new_char_node(hus);
      int is_word = 0;
      if (i == str_len - 1) {
        is_word = 1;
      }
      trie_node_t* new_trie_node = create_trie_node(new_node, is_word);
      if (prev->children == NULL) {
        prev->children = create_hash_map(26);
      }
      put(prev->children, &hus, (void*)new_trie_node);
    }
  }
}

int check_word_exists(trie_node_t* tree_root, char* word) {
  if (tree_root == NULL || word == NULL) {
    return 0;
  }
  size_t str_len = strlen(word);
  if (str_len == 0) {
    return 0;
  }
  trie_node_t* prev = tree_root;
  for (size_t i = 0; i < str_len; i++) {
    char hus = word[i];
    data_object* dt_object = get_data_object_for_key(prev -> children, &hus);
    if (dt_object == NULL) {
      return 0;
    }
    prev = dt_object->value;
  }
  if (prev->is_word == 1) {
    return 1;
  }
  return 0;
}

char** search(trie_node_t* tree_root, char* search_input) {
  if (tree_root == NULL || search_input == NULL) {
    return NULL;
  }
  size_t str_len = strlen(search_input);
  if (str_len == 0) {
    return 0;
  }
  trie_node_t* prev = tree_root;
  for (size_t i = 0; i < str_len; i++) {
    char hus = search_input[i];
    data_object* dt_object = get_data_object_for_key(prev -> children, &hus);
    if (dt_object == NULL) {
      break;
    }
    prev = dt_object->value;
  }
}


