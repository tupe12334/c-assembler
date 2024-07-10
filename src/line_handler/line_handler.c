#include "../../include/line_handler.h"

void line_handler(DynamicArray *program, ParsedLine *parsed_line) {
  switch (parsed_line->line_type) {
  case OPERATION:
    handle_operation(program, parsed_line);
    break;
    // TODO
    //   case INSTRUCTION:
    //     handle_instruction(parsed_line);
    //     break;
  case MACRO:
  case EMPTY:
  default:
    // TODO throw error
    break;
  }
}