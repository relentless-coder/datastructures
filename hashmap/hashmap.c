#include "./hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

hash_map *create_hash_map(size_t given_size) {
  size_t size;
  size = given_size || 50;
  hash_map *hp = malloc(sizeof(hash_map));
  hash_object **elements = malloc(given_size * sizeof(hash_object));
  hp->elements = elements;
  return hp;
}

size_t get_hash(hash_map *h_map, char *key) {
  if (h_map == NULL || key == NULL) {
    return 0;
  }
  int key_sum = 0;
  for (int i = 0; i < strlen(key); i++) {
    int char_int = (int)key[i];
    key_sum += char_int;
  }

  return key_sum % (h_map->size);
}

void put(hash_map *h_map, char *key, void *value) {
  if (key == NULL || value == NULL) {
    return;
  }
  size_t hash_index = get_hash(h_map, key);
  data_object *object_data = malloc(sizeof(data_object));
  if (object_data == NULL) {
    return;
  }
  object_data->key = key;
  object_data->value = value;
  hash_object *new_hash_object = malloc(sizeof(hash_object));
  if (new_hash_object == NULL) {
    return;
  }
  new_hash_object->data = object_data;
  new_hash_object->next = NULL;
  hash_object *existing_hash_object = get_from_hashmap(h_map, key);
  if (existing_hash_object)
    existing_hash_object->next = new_hash_object;
  else
    h_map->elements[hash_index] = new_hash_object;
  return;
}

void remove_from_hashmap(hash_map *h_map, char *key) {
  if (key == NULL) {
    return;
  }
  size_t hash_index = get_hash(h_map, key);
  h_map->elements[hash_index] = NULL;
  return;
}

hash_object *get_from_hashmap(hash_map *h_map, char *key) {
  if (key == NULL) {
    return NULL;
  }
  size_t hash_index = get_hash(h_map, key);
  hash_object *h_object = h_map->elements[hash_index];
  while (h_object != NULL) {
    if (h_object->data->key == key) {
      return h_object;
    }
    h_object = h_object->next;
  }
  return NULL;
}

data_object *get_data_object_for_key(hash_map *h_map, char *key) {
  if (h_map == NULL || key == NULL) {
    return NULL;
  }
  hash_object *h_object = get_from_hashmap(h_map, key);
  if (h_object == NULL) {
    return NULL;
  }
  return h_object->data;
}
