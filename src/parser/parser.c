#include "../../include/get_operators_amount.h"
#include "../../include/get_value.h"
#include "../../include/line.h"
#include "../../include/parse_label.h"
#include "../../include/parse_line_type.h"
#include "../../include/parse_operation.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

ParsedLine *parse_line(TokenizedLine tokenized_line,
                       MetaAssembler meta_assembler) {
  int line_cursor = 0;
  ParsedLine *parsed_line = malloc(sizeof(ParsedLine));
  if (parsed_line == NULL) {
    printf("Failed to allocate memory for parsed_line\n");
    exit(EXIT_FAILURE);
  }
  parsed_line->tokens = tokenized_line;

  parsed_line->line_type =
      command_to_line_type(parsed_line->tokens.type, meta_assembler);

  puts(parsed_line->tokens.type);
  parsed_line->operators_amount =
      get_operators_amount(parsed_line->tokens.type);
  return parsed_line;
}
