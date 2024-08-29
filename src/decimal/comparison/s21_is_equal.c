#include <s21_decimal.h>

#include "../common/s21_common.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  s21_decimal_u left_val = {0};
  left_val.decimal = a;
  s21_decimal_u right_val = {0};
  right_val.decimal = b;

  comparison_status_e status = TRUE;

  if (degree_equalize(&left_val, &right_val) == EQ_OK) {
    for (int i = 2; i >= 0 && status == TRUE; i--) {
      status = (left_val.binary.bits[i] == right_val.binary.bits[i]);
    }
  } else {
    status = FALSE;
  }

  return status;
}