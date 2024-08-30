#ifndef S21_COMMON_H
#define S21_COMMON_H

#include <stdbool.h>
#include <s21_decimal.h>

typedef union {
  uint64_t num;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
    uint32_t high_bits;
    uint32_t low_bits;
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
    uint32_t low_bits;
    uint32_t high_bits;
#endif
  };
} arithmetic_box;

/**
 * @brief Enumeration for the status of the degree equalization operation.
 */
typedef enum {
  /**
   * @brief The left number is bigger.
   */
  A_VAL_BIGGER = -1,
  /**
   * @brief The operation was successful.
   */
  EQ_OK = 0,
  /**
   * @brief The right number is bigger.
   */
  B_VAL_BIGGER = 1
} deg_eq_status;

typedef enum {
  LESS = -1,
  EQUAL = 0,
  GREATER = 1
} mantiss_comp_status;


bool mantiss_mul_by_ten(s21_decimal *val);
deg_eq_status degree_equalize(s21_decimal_u *a, s21_decimal_u *b);
mantiss_comp_status mantiss_compare(s21_decimal_u a, s21_decimal_u b);

#endif