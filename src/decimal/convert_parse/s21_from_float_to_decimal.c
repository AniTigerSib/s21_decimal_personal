#include "../s21_decimal.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

int get_exponent_from_float(const float src, int *exponent);

/**
 * @fn s21_from_float_to_decimal
 * @brief Converts a float value to a s21_decimal structure.
 * @author Michael worfwint
 *
 * This function takes a float value as input and converts it into a s21_decimal structure.
 * The s21_decimal structure is a custom data type that represents a decimal number.
 *
 * @param [in] src The float value to be converted.
 * @param [out] dst A pointer to the s21_decimal structure where the converted value will be stored.
 *
 * @return 0 on success, or a non-zero error code on failure.
 */
int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  if (dst == NULL) return ERR;
  if (isnan(src) || fabs(src) < 1e-28) {
    memset(dst, 0, sizeof(*dst));
    return ERR;
  }
  if (isinf(src) || fabs(src) > 7.9228162514264337593543950335e28) return ERR;

  common_status_e status = COMMON_OK;
  


  return status;
}