#include "../../../include/dynamic_array.h"
#include "../../../include/instructions_handlers.h"
#include "../../../include/instructors.h"
#include "../../../include/line.h"
#include <stdio.h>
#include <string.h>

void handle_instructions(DynamicArray *program, ParsedLine *parsed_line) {

  const char *instruction = parsed_line->tokens.type;
  if (strcmp(instruction, ".string") == 0) {
    handle_string(program, parsed_line);
    return;
  } else if (strcmp(instruction, ".data") == 0) {
    handle_data(program, parsed_line);
    return;
  } else if (strcmp(instruction, ".extern") == 0) {
    handle_externals(program, parsed_line);
    return;
  }
  //  else if (strcmp(instruction, ".entry") == 0) {
  //   return;
  // }
}
