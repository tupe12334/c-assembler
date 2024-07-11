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
  case NUMBER:
    binary_code += ABSOLUTE;
    binary_code += handle_number_operand(operand, side);
    break;
    // case LABEL:
    //   binary_code += RELOCATABLE;
    //   binary_code += handle_label_operand(operand, side);
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
    darray_append(program, binary_code, false);
  }
  if (operator_line->operand_dst != NULL) {
    int binary_code = handle_operand(operator_line->operand_dst, DST);
    darray_append(program, binary_code, false);
  }
}