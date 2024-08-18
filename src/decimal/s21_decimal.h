#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdint.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef enum {
  POSITIVE,
  NEGATIVE
} s21_decimal_sign;

typedef union {
  s21_decimal decimal;
  struct {
    int low_bits;
    int middle_bits;
    int high_bits;
    int free_lower_word : 16; // must be zero
    int degree : 8;
    int free_space : 7; // must be zero
    s21_decimal_sign sign : 1;
  };
} s21_decimal_binary;

typedef enum {
  ARITHMETIC_OK = 0,
  TOO_LARGE,
  TOO_SMALL,
  DIVISION_BY_ZERO
} arithmetic_status_e;

typedef enum {
  FALSE = 0,
  TRUE
} comparison_status_e;

typedef enum {
  COMMON_OK = 0,
  ERR
} common_status_e;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

int s21_is_less(s21_decimal value_1, s21_decimal value_2);
int s21_is_less_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater(s21_decimal value_1, s21_decimal value_2);
int s21_is_greater_or_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_equal(s21_decimal value_1, s21_decimal value_2);
int s21_is_not_equal(s21_decimal value_1, s21_decimal value_2);

int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);

int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

#endif