#include "../../../../include/constants.h"
#include "../../../../include/line.h"
#include "../../../../include/string.h"
#include <stdio.h>
#include <stdlib.h>

int handle_number_operand(Operand *operand, enum OperandSide side) {
  string value = operand->value;
  string trimmed_value = ltrim_x_chars(value, 1);
  int num_value = atoi(trimmed_value) << 3;

  return num_value;
}
