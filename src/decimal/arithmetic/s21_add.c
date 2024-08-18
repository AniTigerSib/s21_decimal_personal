#include <s21_decimal.h>
#include <stdbool.h>

#include "../big_decimal/s21_big_decimal.h"

int is_negative(s21_decimal val) {
  s21_decimal_binary *dec = (s21_decimal_binary *)&val;
  return dec->sign;
}

void to_positive(s21_decimal *val) {
  s21_decimal_binary *dec = (s21_decimal_binary *)val;
  dec->sign = POSITIVE;
}

int decimal_add_binary(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  s21_big_decimal val_1 = decimal_to_big_decimal(value_1);
  s21_big_decimal val_2 = decimal_to_big_decimal(value_2);

  // TODO: Доделать, перенести логику в s21_add, функцию упростить
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res_code = ARITHMETIC_OK;
  int is_preprocessed = false;
  if (!is_negative(value_1) && is_negative(value_2)) {
    is_preprocessed = true;
    to_positive(&value_2);
    res_code = s21_sub(value_1, value_2, result);
  } else if (!is_negative(value_1) && is_negative(value_2)) {
    is_preprocessed = true;
    to_positive(&value_1);
    res_code = s21_sub(value_2, value_1, result);
  }

  if (!is_preprocessed) {
    res_code = decimal_add_binary(value_1, value_2, result);
  }

  return res_code;
}