#include "../../include/line_handler.h"
#include "../../include/program.h"
#include <stdio.h>

void line_handler(Program *program, ParsedLine *parsed_line) {
  switch (parsed_line->line_type) {
  case OPERATION:
    handle_operation(program, parsed_line);
    break;
  case INSTRUCTION:
    handle_instructions(program, parsed_line);
    break;
  case EMPTY:
    break;
  case MACRO:
  default:
    fprintf(stderr, "Unknown line type: %d\n", parsed_line->line_type);
    break;
  }
}
