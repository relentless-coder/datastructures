
#include "../../.lib/munit/munit.h"
#include "tree.h"
#include "../tree_node/tree_node.h"
#include "../../node/node.h"

static node_t* create_mock_node(int value) {
  node_t* node = malloc(sizeof(node_t));
  node->data.ln_int = value;
  return node;
}

/* Test: create_new_tree should return NULL on NULL root */
static MunitResult test_create_new_tree_null_root(const MunitParameter params[], void* data) {
  tree_t* tree = create_new_tree(NULL);
  munit_assert_null(tree);
  return MUNIT_OK;
}

/* Test: create_new_tree returns valid tree and initializes fields */
static MunitResult test_create_new_tree_valid(const MunitParameter params[], void* data) {
  node_t* node = create_mock_node(42);
  tree_node_t* tree_node = create_new_tree_node(node);
  tree_t* tree = create_new_tree(tree_node);
  munit_assert_not_null(tree);
  munit_assert_ptr_equal(tree->root, tree_node);
  munit_assert_ptr_equal(tree_node ->node, node);
  munit_assert_int(tree->size, ==, 1);
  free(tree);
  free_tree_node(tree_node);
  return MUNIT_OK;
}

/* Test: add_tree_node_to_tree should add child correctly */
static MunitResult test_add_tree_node(const MunitParameter params[], void* data) {
  node_t* root_data = create_mock_node(1);
  node_t* child_data = create_mock_node(2);
  tree_node_t* root = create_new_tree_node(root_data);
  tree_t* tree = create_new_tree(root);
  tree_node_t* child = create_new_tree_node(child_data);
  add_tree_node_to_tree(tree, root, child);
  munit_assert_ptr_equal(root->first_child, child);
  free_tree_node(root);
  free(tree);
  return MUNIT_OK;
}

static MunitResult test_remove_tree_node(const MunitParameter params[], void* data) {
  node_t* root_data = create_mock_node(1);
  node_t* child_data = create_mock_node(2);
  tree_node_t* root = create_new_tree_node(root_data);
  tree_node_t* child = create_new_tree_node(child_data);
  int n_result = remove_tree_node_from_tree(root, child);
  munit_assert_int(n_result, ==, 0);
  int result = remove_tree_node_from_tree(root, root);
  munit_assert_int(result, ==, 1);
  free_tree_node(child);
  return MUNIT_OK;
}

static MunitTest tree_tests[] = {
  { "/create_new_tree_null_root", test_create_new_tree_null_root, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/create_new_tree_valid", test_create_new_tree_valid, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/add_tree_node", test_add_tree_node, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { "/remove_tree_node", test_remove_tree_node, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
  { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite tree_suite = {
  "/tree", tree_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
  return munit_suite_main(&tree_suite, (void*) "tree", argc, argv);
}
