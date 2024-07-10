#include "../../../../include/line.h"
#include "../../../../include/operator_validators.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void validate_operand(Operand *operand,
                      unsigned short int valid_address_codes[]) {
  int length = 0;
  while (valid_address_codes[length] != NULL) {
    printf("%d\n", valid_address_codes[length]);
    length++;
  }
  bool is_have_options = length > 0;

  printf("\n%d\n", is_have_options);
  puts(operand->value);
  if (operand != NULL && is_have_options == false) {
    fprintf(stderr, "Error: operand is not allowed for operation\n");
    exit(EXIT_FAILURE);
  }
  printf("Start to validate operand %s\n", operand->value);
  printf("Operand is valid\n");
}
void validate_operands(OperatorLine *operator_line,
                       unsigned short int valid_src_address_codes[],
                       unsigned short int valid_dst_address_codes[]) {

  printf("Start to validate operands for line %s\n",
         operator_line->parsed_line->tokens.line);
  validate_operand(operator_line->operand_dst, valid_dst_address_codes);
  puts("Finish to validate destination operand");
  validate_operand(operator_line->operand_src, valid_src_address_codes);
  puts("Finish to validate source operand");
}