#include "../../../../include/bool.h"
#include "../../../../include/line.h"
#include "../../../../include/operators_handlers.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int handle_operand(Operand *operand, enum OperandSide side) {
  int binary_code = 0;
  if (operand == NULL) {
    fprintf(stderr, "Invalid operand\n");
    exit(EXIT_FAILURE);
  }
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
  bool is_have_src = operator_line->operand_src != NULL;
  bool is_have_dst = operator_line->operand_dst != NULL;

  if (is_have_dst && is_have_src) {
    bool is_src_register =
        operator_line->operand_src->address_type == REGISTER_VALUE ||
        operator_line->operand_src->address_type == REGISTER_ADDRESS;

    bool is_dst_register =
        operator_line->operand_dst->address_type == REGISTER_VALUE ||
        operator_line->operand_dst->address_type == REGISTER_ADDRESS;

    bool is_both_registers = is_dst_register && is_src_register;

    if (is_both_registers) {
      int binary_code = ABSOLUTE;
      binary_code += handler_register_operand(operator_line->operand_dst, DST);
      binary_code += handler_register_operand(operator_line->operand_src, SRC);
      darray_append(program, binary_code, false);
      return;
    }
  }

  if (is_have_src) {
    int binary_code = handle_operand(operator_line->operand_src, SRC);
    darray_append(program, binary_code, false);
  }
  if (is_have_dst) {
    int binary_code = handle_operand(operator_line->operand_dst, DST);
    darray_append(program, binary_code, false);
  }
}
