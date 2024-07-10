#include "../../../../include/dynamic_array.h"
#include "../../../../include/line.h"
#include "../../../../include/operator_validators.h"
#include <stdio.h>

int common_handler(DynamicArray *program, OperatorLine *operator_line) {
  int binary_code = 0;
  int instruction_binary_code = ABSOLUTE;
  binary_code += instruction_binary_code;

  int op_code_binary_section = operator_line->opcode << 11;
  binary_code += op_code_binary_section;
  if (operator_line != NULL && operator_line->operand_dst != NULL &&
      operator_line->operand_dst->address_type != NULL) {
    int dst_address_binary_section = operator_line->operand_dst->address_type
                                     << 3;
    binary_code += dst_address_binary_section;
  }
  if (operator_line != NULL && operator_line->operand_src != NULL &&
      operator_line->operand_src->address_type != NULL) {
    int src_address_binary_section = operator_line->operand_src->address_type
                                     << 7;
    binary_code += src_address_binary_section;
  }

  return binary_code;
}