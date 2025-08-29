#include "../../.lib/munit/munit.h"
#include "binary_tree.h"
#include <stdlib.h>

// Helper: create a node_t with a key
static node_t *make_node(int key) {
    node_t *n = malloc(sizeof(node_t));
    n->data.ln_int = key;
    n -> kind = INTEGER;
    return n;
}

// Helper: create a binary_tree_node_t from a node_t
static binary_tree_node_t *make_bt_node(int key) {
    binary_tree_node_t *btn = malloc(sizeof(binary_tree_node_t));
    btn->node = make_node(key);
    btn->left = NULL;
    btn->right = NULL;
    return btn;
}

// Helper: free a binary_tree_node_t and node_t
static void free_bt_node(binary_tree_node_t *btn) {
    if (!btn) return;
    if (btn->node) free(btn->node);
    free(btn);
}

// ---- Tests ----

// Test tree creation, root assignment
static MunitResult test_create_new_binary_tree(const MunitParameter params[], void* data) {
    binary_tree_node_t *root = make_bt_node(10);
    binary_tree_t *tree = create_new_binary_tree(root);
    munit_assert_not_null(tree);
    munit_assert_ptr_equal(tree->root, root);
    free(tree); // Only frees tree struct, not node
    free_bt_node(root);
    return MUNIT_OK;
}

// Test node insertion and inorder traversal: inserting in sorted order
static MunitResult test_inorder_traversal_sorted(const MunitParameter params[], void* data) {
    binary_tree_node_t *root = make_bt_node(2);
    binary_tree_t *tree = create_new_binary_tree(root);

    binary_tree_node_t *left = make_bt_node(1);
    binary_tree_node_t *right = make_bt_node(3);

    add_node_to_binary_tree(tree, left);
    add_node_to_binary_tree(tree, right);

    munit_assert_ptr_equal(tree -> root ->right, right);
    munit_assert_ptr_equal(tree -> root ->left, left);
    node_t **ordered = collect_nodes_from_tree(tree);
    munit_assert_not_null(ordered);
    munit_assert_int(ordered[0]->data.ln_int, ==, 1);
    munit_assert_int(ordered[1]->data.ln_int, ==, 2);
    munit_assert_int(ordered[2]->data.ln_int, ==, 3);

    free(ordered);
    free_bt_node(right);
    free_bt_node(left);
    free_bt_node(root);
    free(tree);
    return MUNIT_OK;
}

// Test null handling in add_node_to_binary_tree
static MunitResult test_null_insertion(const MunitParameter params[], void* data) {
    add_node_to_binary_tree(NULL, NULL); // Should not crash
    binary_tree_node_t *root = make_bt_node(4);
    binary_tree_t *tree = create_new_binary_tree(root);
    add_node_to_binary_tree(tree, NULL); // Should not crash
    free_bt_node(root);
    free(tree);
    return MUNIT_OK;
}

// Test compare_and_return_smaller_binary_tree_node for NULL inputs
static MunitResult test_compare_smaller_null(const MunitParameter params[], void* data) {
    munit_assert_null(compare_and_return_smaller_binary_tree_node(NULL, NULL));
    binary_tree_node_t *a = make_bt_node(1);
    munit_assert_null(compare_and_return_smaller_binary_tree_node(a, NULL));
    munit_assert_null(compare_and_return_smaller_binary_tree_node(NULL, a));
    free_bt_node(a);
    return MUNIT_OK;
}

// ---- MUnit Runner ----

static MunitTest tests[] = {
    {"test_create_new_binary_tree", test_create_new_binary_tree, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"test_inorder_traversal_sorted", test_inorder_traversal_sorted, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"test_null_insertion", test_null_insertion, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"test_compare_smaller_null", test_compare_smaller_null, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite suite = {
    "/binary_tree_tests",
    tests,
    NULL,
    1,
    MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}

