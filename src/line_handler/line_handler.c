#include "../../include/line_handler.h"
#include "../../include/dictionary.h"
#include "../../include/program.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void debug_table_work(Dictionary *label_table, string label, string address) {
  printf("The existing value for key: %s is %s\n", label,
         lookup(label_table, label));
}

void line_handler(Program *program, Dictionary *label_table,
                  ParsedLine *parsed_line, enum AssemblerPase pase) {
  size_t program_index;
  char program_address[4];

  printf("Starting line handler for line %s\n", parsed_line->tokens.line);
  if (parsed_line->tokens.label != NULL) {
    if (pase == FIRST_RUN) {

      program_index = program_size(program);
      sprintf(program_address, "%zu", program_index);

      debug_table_work(label_table, parsed_line->tokens.label, program_address);

      insert(label_table, parsed_line->tokens.label, program_address);

      debug_table_work(label_table, parsed_line->tokens.label, program_address);
    }
  }
  switch (parsed_line->line_type) {
  case OPERATION:
    handle_operation(program, label_table, parsed_line, pase);
    break;
  case INSTRUCTION:
    handle_instructions(program, label_table, parsed_line, pase);
    break;
  case EMPTY:
  case MACRO:
  default:
    fprintf(stderr, "Unknown line type: %d\n", parsed_line->line_type);
    break;
  }
}
