#include "../../include/get_value.h"
#include "../../include/is_instruction.h"
#include "../../include/line.h"
#include "../../include/parse_label.h"
#include "../../include/parse_line_type.h"
#include "../../include/parse_operation.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

ParsedLine *parse_line(TokenizedLine tokenized_line,
                       MetaAssembler meta_assembler) {
  ParsedLine *parsed_line = malloc(sizeof(ParsedLine));
  if (parsed_line == NULL) {
    fprintf(stderr, "Failed to allocate memory for parsed_line\n");
    exit(EXIT_FAILURE);
  }
  parsed_line->tokens = tokenized_line;

  parsed_line->line_type =
      command_to_line_type(parsed_line->tokens.type, meta_assembler);

  return parsed_line;
}
