#include <stdio.h>
#include "../test.h"
#include "check.h"
#include "common/s21_common.h"
#include "s21_decimal.h"

START_TEST(test_zero__normal) {
  int value = 0;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_zero__normal) {
  int value = -0;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_null_pointer__error) {
  int value = 0;

  ck_assert_int_eq(s21_from_int_to_decimal(value, NULL), ERR);
}
END_TEST

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

START_TEST(test_one_digit_number__normal) {
  int value = 5;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {5, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_one_digit_number__normal) {
  int value = -5;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {5, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_two_digits_number__normal) {
  int value = 74;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {0x4A, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);
  
  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_two_digits_number__normal) {
  int value = -74;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {0x4A, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_three_digits_number__normal) {
  int value = 587;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {587, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_three_digits_number__normal) {
  int value = -587;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {587, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_four_digits_number__normal) {
  int value = 4976;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {4976, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_four_digits_number__normal) {
  int value = -4976;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {4976, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_five_digits_number__normal) {
  int value = 83365;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {83365, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_five_digits_number__normal) {
  int value = -83365;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {83365, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_six_digits_number__normal) {
  int value = 985234;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {985234, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_six_digits_number__normal) {
  int value = -985234;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {985234, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_max_int_number__normal) {
  int value = 214748364;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {214748364, 0, 0},
    .binary.degree = 0,
    .binary.sign = POSITIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

START_TEST(test_negative_max_int_number__normal) {
  int value = -2147483648;
  s21_decimal result = {0};
  s21_decimal_u to_compare = {
    .binary.bits = {2147483648, 0, 0},
    .binary.degree = 0,
    .binary.sign = NEGATIVE
  };

  ck_assert_int_eq(s21_from_int_to_decimal(value, &result), COMMON_OK);

  ck_assert_int_eq(s21_is_equal(result, *((s21_decimal *) &to_compare)), TRUE);
}
END_TEST

Suite *test_s21_from_int_to_decimal() {
  Suite *s = suite_create("s21_from_int_to_decimal");
  TCase *tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_zero__normal);
  tcase_add_test(tc_core, test_negative_zero__normal);
  tcase_add_test(tc_core, test_null_pointer__error);

  tcase_add_test(tc_core, test_one_digit_number__normal);
  tcase_add_test(tc_core, test_negative_one_digit_number__normal);
  tcase_add_test(tc_core, test_two_digits_number__normal);
  tcase_add_test(tc_core, test_negative_two_digits_number__normal);
  tcase_add_test(tc_core, test_three_digits_number__normal);
  tcase_add_test(tc_core, test_negative_three_digits_number__normal);
  tcase_add_test(tc_core, test_four_digits_number__normal);
  tcase_add_test(tc_core, test_negative_four_digits_number__normal);
  tcase_add_test(tc_core, test_five_digits_number__normal);
  tcase_add_test(tc_core, test_negative_five_digits_number__normal);
  tcase_add_test(tc_core, test_six_digits_number__normal);
  tcase_add_test(tc_core, test_negative_six_digits_number__normal);
  tcase_add_test(tc_core, test_max_int_number__normal);
  tcase_add_test(tc_core, test_negative_max_int_number__normal);

  suite_add_tcase(s, tc_core);
  return s;
}