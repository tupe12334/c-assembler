#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/operator_validators.h"
#include "../../../include/operators_handlers.h"
#include <stdbool.h>
#include <stdio.h>

void valid_prn_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[0];
  unsigned short int valid_dst_address_codes[] = {0, 1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}

void prn_operator_handler(DynamicArray *program, OperatorLine *operator_line) {
  // valid_prn_operands(operator_line);
  int binary_code = common_handler(program, operator_line);
  unsigned short op_code = operator_line->opcode;
  int op_code_binary_section = op_code << 11;

  darray_append(program, binary_code, false);
}