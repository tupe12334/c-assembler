#include "../../../include/line_handler.h"
#include "../../../include/op_codes.h"
#include "../../../include/operator_parser.h"
#include "../../../include/operator_validators.h"
#include "../../../include/operators_handlers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void validate_operator(OperatorLine *operator_line) {
  switch (operator_line->opcode) {
  case 2:
    valid_add_operands(operator_line);
    break;
  case 4:
    valid_lea_operands(operator_line);
    break;
  case 12:
    valid_prn_operands(operator_line);
    break;
  case 13:
    valid_jsr_operands(operator_line);
    break;
  default:
    printf("Error in handle_operation: unknown operation type %s\n",
           operator_line->parsed_line->tokens.type);
    exit(EXIT_FAILURE);
    break;
  }
}

void handle_operation(DynamicArray *program, ParsedLine *parsed_line) {
  OperatorLine *operator_line;
  printf("Start to handle operation type %s\n", parsed_line->tokens.type);
  operator_line = parse_operator_line(parsed_line);

  validate_operator(operator_line);

  int binary_code = common_handler(program, operator_line);
  darray_append(program, binary_code, false);

  handle_operands(program, operator_line);
}
