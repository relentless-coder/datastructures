
#include "../.lib/munit/munit.h"
#include "./hashmap.h"
#include <string.h>

static MunitResult test_create_hash_map(const MunitParameter params[], void *data) {
  hash_map *h = create_hash_map(20);
  munit_assert_not_null(h);
  return MUNIT_OK;
}

static MunitResult test_put_and_get(const MunitParameter params[], void *data) {
  hash_map *h = create_hash_map(30);
  char *val = "valueA";
  put(h, "key1", (void *)val);

  data_object *obj = get_data_object_for_key(h, "key1");
  munit_assert_not_null(obj);
  munit_assert_string_equal(obj->key, "key1");
  munit_assert_string_equal((char *)obj->value, val);
  return MUNIT_OK;
}

static MunitResult test_remove(const MunitParameter params[], void *data) {
  hash_map *h = create_hash_map(10);
  char *val1 = "valueB";
  char *val2 = "valueC";
  put(h, "key2", (void *)val1);
  put(h, "key10", (void *)val2);

  remove_from_hashmap(h, "key2");
  data_object *obj = get_data_object_for_key(h, "key2");
  munit_assert_null(obj);

  data_object *avl_obj = get_data_object_for_key(h, "key10");
  munit_assert_string_equal(avl_obj->key, "key10");
  munit_assert_string_equal((char *)avl_obj->value, val2);
  return MUNIT_OK;
}

static MunitResult test_null_key(const MunitParameter params[], void *data) {
  hash_map *h = create_hash_map(10);
  munit_assert_null(get_data_object_for_key(h, NULL));
  // Should not crash or alter contents
  put(h, NULL, (void *)"valueC");
  remove_from_hashmap(h, NULL);
  return MUNIT_OK;
}

static MunitResult test_collision_handling(const MunitParameter params[], void *data) {
  hash_map *h = create_hash_map(1); // Force all keys into index 0
  char *val1 = "valueA";
  char *val2 = "valueB";
  put(h, "key1", (void *)val1);
  put(h, "key2", (void *)val2);

  hash_object *obj1 = get_from_hashmap(h, "key1");
  hash_object *obj2 = get_from_hashmap(h, "key2");

  munit_assert_not_null(obj1);
  munit_assert_not_null(obj2);

  munit_assert_string_equal(obj1->data->key, "key1");
  munit_assert_string_equal((char *)obj1->data->value, val1);

  munit_assert_string_equal(obj2->data->key, "key2");
  munit_assert_string_equal((char *)obj2->data->value, val2);

  return MUNIT_OK;
}

static MunitTest test_suite_tests[] = {
    {"/create_hash_map", test_create_hash_map, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/put_and_get",     test_put_and_get,     NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/remove",          test_remove,          NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/null_key",        test_null_key,        NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {"/collision_handling", test_collision_handling, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL},
    {NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL}
};

static const MunitSuite test_suite = {
    "/hashmap-tests", test_suite_tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char *argv[]) {
  return munit_suite_main(&test_suite, NULL, argc, argv);
}
