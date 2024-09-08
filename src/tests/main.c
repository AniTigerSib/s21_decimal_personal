#include <s21_decimal.h>
#include <string.h>
#include <stdio.h>
#include "test.h"

START_TEST(test_test) {
  ck_assert_int_eq(1, 1);
}
END_TEST
Suite *test_suite() {
  Suite *s = suite_create("tests_");
  TCase *tc = tcase_create("test_Tcase");
  tcase_add_test(tc, test_test);
  suite_add_tcase(s, tc);
  return s;
}

int main() {
  int number_failed;
  Suite *suites[] = {test_suite(), test_s21_is_equal(), test_s21_from_int_to_decimal()};
  char *suite_names[] = {"test_suite", "comparison:test_s21_is_equal", "convert_parse:test_s21_from_int_to_decimal"};
  int n_test = sizeof(suites) / sizeof(suites[0]);
  for (int i=0;i<n_test;i++) {
    char temp_name[150] = "../logs/";
    strcat(temp_name, suite_names[i]);
    SRunner *sr = srunner_create(suites[i]);
    srunner_set_log(sr, temp_name);
    srunner_run_all(sr, CK_NORMAL);
    number_failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  // printf("%d\n", number_failed);
  // return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
  return 0;
}