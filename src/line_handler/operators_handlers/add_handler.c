#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/operator_validators.h"
#include "../../../include/operators_handlers.h"
#include <stdbool.h>
#include <stdio.h>

void valid_add_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {0, 1, 2, 3};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}

void add_operator_handler(DynamicArray *program, OperatorLine *operator_line) {
  valid_add_operands(operator_line);
  int binary_code = common_handler(program, operator_line);
  darray_append(program, binary_code, false);

  if (operator_line->operand_src != NULL) {
    int src_binary_code = 0;
    switch (operator_line->operand_src->address_type) {
    // case:
    //   NUMBER
    //   darray_append(program, atoi(operator_line->operand_dst->value), false);
    //   break;
    // case LABEL:
    //   darray_append(program, 0, false);
    //   break;
    case REGISTER_VALUE:
    case REGISTER_ADDRESS:
      src_binary_code += ABSOLUTE;
      src_binary_code +=
          handler_register_operand(operator_line->operand_src, SRC);
      break;
    }
    darray_append(program, src_binary_code, false);
  }
}