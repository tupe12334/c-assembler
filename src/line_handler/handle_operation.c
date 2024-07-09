#include "../../include/line_handler.h"
#include "../../include/op_codes.h"
#include "../../include/operator_parser.h"
#include <stdio.h>
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

void handle_operation(ParsedLine *parsed_line) {
  OperatorLine *operator_line;
  printf("Start to handle operation type %s\n", parsed_line->tokens.type);
  operator_line = parse_operator_line(parsed_line);

  from_opcode_to_number(parsed_line->tokens.type);
}
