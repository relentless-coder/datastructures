#include <stdlib.h>
#include <string.h>
#include "../.lib/munit/munit.h"
#include "../node/node.h"

static MunitResult
test_create_new_int_node(const MunitParameter params[], void *data) {
    node_t *node = create_new_int_node(123);
    munit_assert_not_null(node);
    munit_assert_int(node->kind, ==, INTEGER);
    munit_assert_int(node->data.ln_int, ==, 123);
    free_node(node);
    return MUNIT_OK;
}

static MunitResult
test_create_new_float_node(const MunitParameter params[], void *data) {
    node_t *node = create_new_float_node(3.14f);
    munit_assert_not_null(node);
    munit_assert_float(node -> kind, ==, FLOAT);
    munit_assert_float(node->data.ln_float, ==, 3.14);
    free_node(node);
    return MUNIT_OK;
}

static MunitResult
test_create_new_char_node(const MunitParameter params[], void *data) {
  node_t *node = create_new_char_node('h');
  munit_assert_not_null(node);
  munit_assert_char(node -> kind, ==, CHAR);
  munit_assert_char(node -> data.ln_char, ==, 'h');
  
  free_node(node);
  return MUNIT_OK;
}

static MunitResult
test_create_new_string_node(const MunitParameter params[], void *data) {
    node_t *node = create_new_string_node("hello");
    munit_assert_not_null(node);
    munit_assert_int(node->kind, ==, STRING);
    munit_assert_not_null(node->data.ln_string);
    munit_assert_string_equal(node->data.ln_string, "hello");
    free_node(node);
    return MUNIT_OK;
}

static MunitTest node_tests[] = {
    { "/create-new-int-node", test_create_new_int_node, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/create-new-float-node", test_create_new_float_node, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/create-new-char-node", test_create_new_char_node, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    { "/create-new-string-node", test_create_new_string_node, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite node_test_suite = {
    "/node", node_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&node_test_suite, NULL, argc, argv);
}

