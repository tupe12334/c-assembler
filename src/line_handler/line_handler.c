#include "../../include/line_handler.h"
#include "../../include/dictionary.h"
#include "../../include/program.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

void start_line_handler_log(ParsedLine *parsed_line) {
  printf("Starting line handler for line %s\n", parsed_line->tokens.line);
}

void line_handler(Program *program, Dictionary *label_table,
                  ParsedLine *parsed_line, MetaAssembler *meta_assembler) {
  size_t program_index;
  char program_address[4];

  start_line_handler_log(parsed_line);
  if (parsed_line->tokens.label != NULL) {
    program_index = program_size(program);
    sprintf(program_address, "%zu", program_index);
    insert(label_table, parsed_line->tokens.label, program_address);
  }
  switch (parsed_line->line_type) {
  case OPERATION:
    handle_operation(program, label_table, parsed_line);
    break;
  case INSTRUCTION:
    handle_instructions(program, label_table, parsed_line);
    break;
  case EMPTY:
  case MACRO:
  default:
    fprintf(stderr, "Unknown line type: %d\n", parsed_line->line_type);
    break;
  }
}
