#include "../s21_decimal.h"

#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

/**
 * @brief Converts an integer to a decimal number.
 *
 * This function converts the input integer to a decimal number and stores it in the
 * provided s21_decimal structure.
 *
 * @param src The integer to be converted.
 * @param dst Pointer to the s21_decimal structure that will store the decimal number.
 *
 * @return The status of the operation, which can be COMMON_OK or ERR.
 */
int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  /**
   * @brief Status of the operation.
   */
  common_status_e status = COMMON_OK;

  /**
   * @brief Temporary s21_decimal_u structure to store the decimal number.
   */
  s21_decimal_u *val = (s21_decimal_u *)dst;

  /**
   * @brief Checks if there is NULL pointer given as input parameter.
   */
  status = (dst == NULL) * ERR;

  /**
   * @brief Converts the integer to a decimal number.
   */
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

  /**
   * @return The status of the operation.
   */
  return status;
}