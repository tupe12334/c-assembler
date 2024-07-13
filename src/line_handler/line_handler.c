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
  case EMPTY:
    break;
  case MACRO:
  default:
    fprintf(stderr, "Unknown line type: %d\n", parsed_line->line_type);
    break;
  }
}
