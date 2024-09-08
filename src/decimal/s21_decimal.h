#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#include <stdint.h>
#include <endian.h>

typedef struct {
  uint32_t bits[4];
} s21_decimal;

typedef enum {
  POSITIVE = 0,
  NEGATIVE
} s21_decimal_sign;

typedef union {
  s21_decimal decimal;
  struct {
#if __BYTE_ORDER == __BIG_ENDIAN
  s21_decimal_sign sign : 1;
  uint8_t free_space1 : 7; // must be zero
  uint8_t degree : 8;
  uint16_t free_space0 : 16; // must be zero
  uint32_t bits[3];
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
  uint32_t bits[3];
  uint16_t free_space0 : 16; // must be zero
  uint8_t degree : 8;
  uint8_t free_space1 : 7; // must be zero
  s21_decimal_sign sign : 1;
#endif
  } binary;
} s21_decimal_u;

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