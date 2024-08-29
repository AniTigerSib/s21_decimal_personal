#include "../s21_decimal.h"

#include "../common/s21_common.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  comparison_status_e status = FALSE;
  deg_eq_status eq_status = degree_equalize((s21_decimal_u *)&a,
                                            (s21_decimal_u *)&b);

  if (eq_status == EQ_OK) {
    for (int i = 2; i >= 0 && status == FALSE; i--) {
      status = (((s21_decimal_u)a).binary.bits[i] >
                ((s21_decimal_u)b).binary.bits[i]);
    }
  } else if (eq_status == A_VAL_BIGGER) {
    status = TRUE;
  }

  return status;
}