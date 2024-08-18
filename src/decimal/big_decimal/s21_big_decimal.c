#include "s21_big_decimal.h"
#include <stdint.h>

#include "s21_decimal.h"

s21_big_decimal decimal_to_big_decimal(s21_decimal val) {
  s21_decimal_binary *dec = (s21_decimal_binary *)&val;
  s21_big_decimal res;
  res.sign = dec->sign;
  res.degree = dec->degree;
  for (int i = 0; i < 3; i++) {
    res.bytes[i] = val.bits[i];
  }
  return res;
}

int dig_decimal_to_decimal(s21_big_decimal val, s21_decimal *result) {
  if (val.degree > 28) return SMALL;

  int res_code = BDEC_OK;
  s21_decimal_binary *dec = (s21_decimal_binary *)result;
  dec->degree = val.degree;
  dec->sign = val.sign;

  // TODO: Сделать проверку на вмещение в decimal и прочее

  return res_code;
}

void mantiss_mul_by_ten(s21_big_decimal *val) {
  arithmetic_box box = {0};
  uint32_t remainder = 0;
  for (int i = 0; i < 7; i++) {
    box.num = val->bytes[i];
    box.num *= 10;
    val->bytes[i] = remainder + box.low_bits;
    remainder = box.high_bits;
  }
}

int bdec_bank_round(s21_big_decimal val, uint32_t remainder) {
  if (remainder != 0) {

  }

  // TODO: Доделать банковское округление
}

void degree_equalize(s21_big_decimal *a, s21_big_decimal *b) {
  while (a->degree > b->degree) {
    b->degree++;
    mantiss_mul_by_ten(b);
  }
  while (b->degree > a->degree) {
    a->degree++;
    mantiss_mul_by_ten(a);
  }
}

int bdec_add(s21_big_decimal a, s21_big_decimal b, s21_big_decimal *res) {
  int res_code = BDEC_OK;

  degree_equalize(&a, &b);

  arithmetic_box box = {0};
  uint32_t remainder = 0;
  for (int i = 0; i < 7; i++) {
    box.num = a.bytes[i] + b.bytes[i] + remainder;
    res->bytes[i] = box.low_bits;
    remainder = box.high_bits;
  }

  // TODO: доделать

  return res_code;
}