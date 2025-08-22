#include <stdlib.h>
#include <string.h>

#include "node.h"

node_t *create_new_int_node(int value) {
  node_t *new_int_node = malloc(sizeof(node_t));
  if (new_int_node == NULL) {
    return NULL;
  }
  new_int_node->kind = INTEGER;
  new_int_node->data.ln_int = value;
  return new_int_node;
}

node_t *create_new_float_node(float value) {
  node_t *new_float_node = malloc(sizeof(node_t));
  if (new_float_node == NULL) {
    return NULL;
  }
  new_float_node->kind = FLOAT;
  new_float_node->data.ln_float = value;
  return new_float_node;
}

node_t *create_new_char_node(char value) {
  node_t *new_char_node = malloc(sizeof(node_t));
  if (new_char_node == NULL) {
    return NULL;
  }
  new_char_node->kind = CHAR;
  new_char_node->data.ln_char = value;
  return new_char_node;
}

node_t *create_new_string_node(char *value) {
  node_t *new_string_node = malloc(sizeof(node_t));
  if (new_string_node == NULL) {
    return NULL;
  }
  char *new_string = malloc(strlen(value) + 1);
  if (new_string == NULL) {
    free(new_string_node);
    return NULL;
  }
  strcpy(new_string, value);
  new_string_node->kind = STRING;
  new_string_node->data.ln_string = new_string;
  return new_string_node;
}

void free_node(node_t *node) {
  if (node == NULL) {
    return;
  }

  switch (node->kind) {
  case INTEGER:
  case FLOAT:
  case CHAR:
    free(node);
    return;
  default:
    return;
  }
}

node_t *compare_and_return_smaller_node(node_t *a, node_t *b) {
  switch (a->kind) {
    case INTEGER:
      if (a->data.ln_int <= b->data.ln_int) {
        return a;
      } else {
        return b;
      }
      break;
    case FLOAT:
      if (a->data.ln_int <= b->data.ln_int) {
        return a;
      } else {
        return b;
      }
      break;
    case CHAR:
      if (a -> data.ln_char <= b -> data.ln_char) {
        return a;
      } else {
        return b;
      }
      break;
    default:
      return NULL;
  }
}
