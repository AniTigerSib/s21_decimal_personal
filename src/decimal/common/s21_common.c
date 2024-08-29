#include "s21_common.h"
#include "s21_decimal.h"

/**
 * @brief Multiplies the mantissa of a decimal number by 10.
 *
 * This function multiplies the mantissa of the input decimal number by 10.
 * It uses an arithmetic box to perform the multiplication and handles the overflow.
 *
 * @param val Pointer to the s21_decimal structure that represents the decimal number.
 *
 * @return true if an overflow occurred, false otherwise.
 */
bool mantiss_mul_by_ten(s21_decimal *val) {
  /**
   * @brief Temporary copy of the input decimal number.
   */
  s21_decimal_u copy_val = {0};
  copy_val.decimal = *val;

  /**
   * @brief Arithmetic box to perform the multiplication.
   */
  arithmetic_box box = {0};

  /**
   * @brief Remainder from the multiplication.
   */
  uint32_t remainder = 0;

  /**
   * @brief Flag to indicate if an overflow occurred.
   */
  bool overflow = true;

  /**
   * @brief Multiplies the mantissa of the decimal number by 10.
   */
  for (int i = 0; i < 3; i++) {
    box.num = copy_val.binary.bits[i];
    box.num = (box.num * 10) + remainder;
    copy_val.binary.bits[i] = box.low_bits;
    remainder = box.high_bits;
  }

  /**
   * @brief If no overflow occurred, update the input decimal number.
   */
  if (remainder == 0) {
    overflow = false;
    *val = copy_val.decimal;
  }

  /**
   * @return true if an overflow occurred, false otherwise.
   */
  return overflow;
}

/**
 * @brief Equalizes the degrees of two decimal numbers.
 *
 * This function equalizes the degrees of the two input decimal numbers by multiplying
 * the mantissa of the smaller number by 10 until it has the same degree as the larger number.
 *
 * @param a Pointer to the first s21_decimal_u structure that represents the first decimal number.
 * @param b Pointer to the second s21_decimal_u structure that represents the second decimal number.
 *
 * @return The status of the operation, which can be OK, A_VAL_BIGGER, or B_VAL_BIGGER.
 */
deg_eq_status degree_equalize(s21_decimal_u *a, s21_decimal_u *b) {
  /**
   * @brief Status of the operation.
   */
  deg_eq_status status = EQ_OK;

  /**
   * @brief Equalizes the degrees of the two decimal numbers.
   */
  while (a->binary.degree > b->binary.degree && status == EQ_OK) {
    if (mantiss_mul_by_ten(&b->decimal)) {
      status = B_VAL_BIGGER;
    } else {
      b->binary.degree++;
    }
  }
  while (b->binary.degree > a->binary.degree && status == EQ_OK) {
    if (mantiss_mul_by_ten(&a->decimal)) {
      status = A_VAL_BIGGER;
    } else {
      a->binary.degree++;
    }
  }

  /**
   * @return The status of the operation.
   */
  return status;
}

mantiss_comp_status mantiss_compare(s21_decimal_u a, s21_decimal_u b) {
  mantiss_comp_status status = EQUAL;

  int i = 2;
  while (i >= 0 && ((s21_decimal_u)a).binary.bits[i] == 0 &&
                   ((s21_decimal_u)b).binary.bits[i] == 0) {
    i--;
  }

  if (i != -1) {
    if (((s21_decimal_u)a).binary.bits[i] >
        ((s21_decimal_u)b).binary.bits[i]) {
      status = GREATER;
    } else if (((s21_decimal_u)a).binary.bits[i] <
               ((s21_decimal_u)b).binary.bits[i]) {
      status = LESS;
    }
  }

  return status;
}