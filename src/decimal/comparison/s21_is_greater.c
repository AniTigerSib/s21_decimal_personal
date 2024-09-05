#include "../s21_decimal.h"

#include "../common/s21_common.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  comparison_status_e status = FALSE;
  deg_eq_status eq_status = EQ_OK;

  if (((s21_decimal_u)a).binary.sign == ((s21_decimal_u)b).binary.sign) {
    eq_status = degree_equalize(((s21_decimal_u *)&a), ((s21_decimal_u *)&b));
    if (eq_status == EQ_OK) {
      if (((s21_decimal_u)a).binary.sign == POSITIVE) {
        status = mantiss_compare(((s21_decimal_u)a), ((s21_decimal_u)b)) == GREATER;
      } else {
        status = mantiss_compare(((s21_decimal_u)a), ((s21_decimal_u)b)) == LESS;
      }
    } else if (eq_status == A_VAL_BIGGER) {
      status = TRUE;
    }
  } else {
    if (((s21_decimal_u)a).binary.sign == POSITIVE) {
      status = TRUE;
    } else {
      status = FALSE;
    }
  }

  return status;
}