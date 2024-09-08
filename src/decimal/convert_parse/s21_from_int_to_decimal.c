#include "../s21_decimal.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  common_status_e status = (dst == NULL) * ERR;
  s21_decimal_u *val = (s21_decimal_u *)dst;
  if (status == COMMON_OK) {
    val->binary.sign = (src < 0) * NEGATIVE;
    
    if (src == INT_MIN) {
      val->binary.bits[0] = (uint32_t) INT_MAX + 1;
      src = 0;
    } else {
      src = abs(src);
    }

    for (int i = 0; src > 0; i++) {
      unsigned int to_append = (src % 10) * (int)pow(10, i);
      val->binary.bits[0] += to_append;
      src /= 10;
    }
  }
  return status;
}