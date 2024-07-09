#include "../../include/line_handler.h"
#include "../../include/op_codes.h"
#include "../../include/operator_parser.h"
#include "../../include/operators_handlers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int from_opcode_to_number(char *opcode) {
  // get the index of the opcode in the array
  const int op_codes_length = get_op_codes_length();
  int opcode_number;
  int i;
  for (i = 0; i < op_codes_length; i++) {
    const char *op_code = get_op_codes()[i];
    if (strcmp(opcode, op_code) == 0) {
      opcode_number = i;
      break;
    }
  }
  return opcode_number;
}

void create_operator_line(DynamicArray *program, OperatorLine *operator_line) {}

void handle_operation(DynamicArray *program, ParsedLine *parsed_line) {
  OperatorLine *operator_line;
  printf("Start to handle operation type %s\n", parsed_line->tokens.type);
  operator_line = parse_operator_line(parsed_line);

  switch (operator_line->opcode) {
  case 2:
    add_operator_handler();
    break;
  default:
    printf("Error in handle_operation: unknown operation type %s\n",
           parsed_line->tokens.type);
    exit(5);
    break;
  }
  from_opcode_to_number(parsed_line->tokens.type);
}
