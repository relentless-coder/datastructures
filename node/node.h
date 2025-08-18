typedef enum {
  INTEGER,
  FLOAT,
  CHAR,
  STRING
} list_node_kind_t;

typedef union {
  int ln_int;
  float ln_float;
  char ln_char;
  char* ln_string;
} list_node_data_t;


typedef struct Node {
  list_node_kind_t kind;
  list_node_data_t data;
} node_t;


node_t* create_new_int_node(int value);
node_t* create_new_float_node(float value);
node_t* create_new_char_node(char value);
node_t* create_new_string_node(char* value);
void free_node(node_t* node);
