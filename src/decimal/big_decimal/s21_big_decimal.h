#ifndef S21_BIG_DECIMAL_H
#define S21_BIG_DECIMAL_H

#include <s21_decimal.h>
#include <stdint.h>

typedef struct {
  uint32_t bytes[7];
  s21_decimal_sign sign;
  uint32_t degree;
} s21_big_decimal;

typedef union {
  uint64_t num;
  struct {
    uint32_t high_bits;
    uint32_t low_bits;
  };
} arithmetic_box;

typedef enum {
  BDEC_OK,
  LARGE,
  SMALL,
  DIV_BY_ZERO
} bdecimal_rcodes;

s21_big_decimal decimal_to_big_decimal(s21_decimal val);
int dig_decimal_to_decimal(s21_big_decimal val, s21_decimal *result);
int to_decimal(s21_big_decimal val, s21_decimal *result);

#endif