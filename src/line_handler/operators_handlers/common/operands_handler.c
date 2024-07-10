#include "../../../../include/line.h"
#include "../../../../include/operators_handlers.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int handle_operand(Operand *operand, enum OperandSide side) {
  if (operand == NULL) {
    fprintf(stderr, "Invalid operand\n");
    exit(EXIT_FAILURE);
  }
  int binary_code = 0;
  switch (operand->address_type) {
    // case:
    //   NUMBER
    //   darray_append(program, atoi(operator_line->operand_dst->value), false);
    //   break;
  case LABEL:
    puts("sdafdsakjfkl");
    break;
  case REGISTER_VALUE:
  case REGISTER_ADDRESS:
    binary_code += ABSOLUTE;
    binary_code += handler_register_operand(operand, side);
    break;
  }

  return binary_code;
}

void handle_operands(DynamicArray *program, OperatorLine *operator_line) {

  if (operator_line->operand_src != NULL) {
    int binary_code = handle_operand(operator_line->operand_src, SRC);
    printf("Binary code: %d\n", binary_code);
    darray_append(program, binary_code, false);
  }
  if (operator_line->operand_dst != NULL) {
    int binary_code = handle_operand(operator_line->operand_dst, DST);
    darray_append(program, binary_code, false);
  }
}