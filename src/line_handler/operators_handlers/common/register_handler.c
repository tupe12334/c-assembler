#include "../../../../include/constants.h"
#include "../../../../include/line.h"
#include "../../../../include/regex.h"
#include <stdio.h>
#include <stdlib.h>

#define REGISTER_NUMBER_REGEX "([0-7])"

unsigned short int extract_register_number(string operand_value) {
  string str_number = extract_word(operand_value, REGISTER_NUMBER_REGEX);
  return atoi(str_number);
}
int handler_register_operand(Operand *operand, enum OperandSide side) {
  unsigned short int register_number = extract_register_number(operand->value);
  int binary_code = 0;
  switch (side) {
  case SRC:
    binary_code = register_number << 6;
    break;
  case DST:
    binary_code = register_number << 3;
    break;
  default:
    fprintf(stderr, "Invalid operand side\n");
    exit(EXIT_FAILURE);
  }
  return binary_code;
}
