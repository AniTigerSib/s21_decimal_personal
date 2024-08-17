#include <check.h>
#include <s21_decimal.h>

START_TEST(sub_template_test) {
  s21_decimal a;
  s21_decimal b;
  s21_decimal c;
  s21_sub(a, b, &c);
  ck_assert_int_eq(1, 1);
}

Suite *test_s21_sub() {
  Suite *s = suite_create("S21 Decimal sub");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, sub_template_test);
  
  suite_add_tcase(s, tc_core);
  return s;
}