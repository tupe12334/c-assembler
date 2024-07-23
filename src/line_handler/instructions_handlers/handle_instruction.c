#include "../../../include/dictionary.h"
#include "../../../include/dynamic_array.h"
#include "../../../include/instructions_handlers.h"
#include "../../../include/instructors.h"
#include "../../../include/line.h"
#include "../../../include/program.h"
#include <stdio.h>
#include <string.h>

void handle_instructions(Program *program, Dictionary *label_table,
                         ParsedLine *parsed_line, enum AssemblerPase pase) {

  const string instruction = parsed_line->tokens.type;
  if (strcmp(instruction, ".string") == 0) {
    handle_string(program, parsed_line);
    return;
  } else if (strcmp(instruction, ".data") == 0) {
    handle_data(program, parsed_line);
    return;
  } else if (strcmp(instruction, ".extern") == 0) {
    handle_externals(label_table, parsed_line);
    return;
  } else if (strcmp(instruction, ".entry") == 0 && pase == SECOND_RUN) {
    handle_entries(program, label_table, parsed_line);
    return;
  }
  return;
}
