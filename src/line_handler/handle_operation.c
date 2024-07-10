#include "../../include/line_handler.h"
#include "../../include/op_codes.h"
#include "../../include/operator_parser.h"
#include "../../include/operator_validators.h"
#include "../../include/operators_handlers.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_operation(DynamicArray *program, ParsedLine *parsed_line) {
  OperatorLine *operator_line;
  printf("Start to handle operation type %s\n", parsed_line->tokens.type);
  operator_line = parse_operator_line(parsed_line);

  switch (operator_line->opcode) {
  case 2:
    add_operator_handler(program, operator_line);
    break;
  case 12:
    prn_operator_handler(program, operator_line);
    break;
  // case 13:
  //   jsr_operator_handler(program, operator_line);
  //   break;
  default:
    printf("Error in handle_operation: unknown operation type %s\n",
           parsed_line->tokens.type);
    exit(5);
    break;
  }
}
