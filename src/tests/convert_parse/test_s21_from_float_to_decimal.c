#include "../test.h"

#include <s21_decimal.h>

#include <stdlib.h>

START_TEST(test_s21_from_float_to_decimal_null_pointer)
{
  s21_decimal *decimal = NULL;
  const float num = 0.0f;
  const common_status_e expected_res = ERR;
  int res = s21_from_float_to_decimal(num, decimal);
  ck_assert_msg(res == expected_res, "FtoDECtest: (%f, %p) given\t|\tExpected %d return code\t|\tGot %d", num, decimal, expected_res, res);
  ck_assert_msg(decimal == NULL, "FtoDECtest: (%f, %p) given\t|\tExpected NULL decimal\t|\tGot %p", num, decimal, decimal);
}
END_TEST



Suite *test_s21_from_float_to_decimal() {
  Suite *s = suite_create("s21_from_float_to_decimal_test");
  TCase *tc_core = tcase_create("Core");

  // tcase_add_test(tc_core, add_simple_test);

  suite_add_tcase(s, tc_core);
  return s;
}