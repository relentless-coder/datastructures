#include <stdio.h>

typedef struct HashObject hash_object;
typedef struct HashMap hash_map;

typedef struct DataObject {
  char* key;
  void* value;
} data_object;

typedef struct HashObject {
  data_object* data;
  hash_object* next;
} hash_object;

typedef struct HashMap {
  size_t size;
  hash_object** elements;
} hash_map;

size_t get_hash(hash_map* h_map, char* key);
hash_map* create_hash_map(size_t size);
void put(hash_map* h_map, char* key, void* value);
hash_object* get_from_hashmap(hash_map* h_map, char* key);
void remove_from_hashmap(hash_map* h_map, char* key);
data_object* get_data_object_for_key(hash_map* h_map, char* key);
