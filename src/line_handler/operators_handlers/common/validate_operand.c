#include "../../../../include/bool.h"
#include "../../../../include/line.h"
#include "../../../../include/operator_validators.h"
#include <stdio.h>
#include <stdlib.h>

void validate_operand(Operand *operand,
                      unsigned short int valid_address_codes[]) {
  Bool is_have_options;
  int i = 0;
  while (valid_address_codes[i] >= 0 && valid_address_codes[i] <= 3) {
    i++;
  }
  is_have_options = i > 0;
  if (operand != NULL && is_have_options == false) {
    fprintf(stderr, "Error: operand is not allowed for operation\n");
    exit(EXIT_FAILURE);
  }
}
void validate_operands(OperatorLine *operator_line,
                       unsigned short int valid_src_address_codes[],
                       unsigned short int valid_dst_address_codes[]) {
  validate_operand(operator_line->operand_dst, valid_dst_address_codes);
  validate_operand(operator_line->operand_src, valid_src_address_codes);
}
