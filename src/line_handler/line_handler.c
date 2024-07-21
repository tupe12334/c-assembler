#include "../../include/line_handler.h"
#include "../../include/dictionary.h"
#include "../../include/program.h"
#include <stdio.h>

void start_line_handler_log(ParsedLine *parsed_line) {
  printf("Starting line handler for line %s\n", parsed_line->tokens.line);
}

void line_handler(Program *program, Dictionary *label_table,
                  ParsedLine *parsed_line, MetaAssembler meta_assembler) {
  start_line_handler_log(parsed_line);
  string program_address;
  if (parsed_line->tokens.label != NULL) {
    sprintf(program_address, "%zu", program->darray->size);
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
