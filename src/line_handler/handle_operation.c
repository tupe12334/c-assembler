#include "../../include/line_handler.h"
#include <stdio.h>

void handle_operation(ParsedLine *parsed_line) {

  printf("Start to handle operation type %s\n", parsed_line->tokens.type);
}
