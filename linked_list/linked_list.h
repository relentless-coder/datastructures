#include <stddef.h>

typedef struct ListNode list_node_t;
typedef struct Node node_t;

typedef struct ListNode {
  node_t *node;
  list_node_t *next;
} list_node_t;

typedef struct LinkedList {
  list_node_t *head;
  list_node_t *tail;
  int length;
} linked_list_t;

linked_list_t* create_new_linked_list();
list_node_t* create_new_list_node(node_t *node);
void add_node(linked_list_t* list, node_t *node);
void remove_head(linked_list_t* list);

