#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/operator_validators.h"
#include "../../../include/operators_handlers.h"
#include <stdbool.h>
#include <stdio.h>

void valid_jsr_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}

void jsr_operator_handler(DynamicArray *program, OperatorLine *operator_line) {
  valid_jsr_operands(operator_line);
}