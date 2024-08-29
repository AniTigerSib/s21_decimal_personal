#include <s21_decimal.h>

#include "../common/s21_common.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {

  comparison_status_e status = (((s21_decimal_u)a).binary.sign ==
                                ((s21_decimal_u)b).binary.sign) * TRUE;

  if (status == TRUE && degree_equalize((s21_decimal_u *)&a,
                                        (s21_decimal_u *)&b) == EQ_OK) {
    for (int i = 2; status == TRUE && i >= 0; i--) {
      status = (((s21_decimal_u)a).binary.bits[i] ==
                ((s21_decimal_u)b).binary.bits[i]);
    }
  } else {
    status = FALSE;
  }

  return status;
}