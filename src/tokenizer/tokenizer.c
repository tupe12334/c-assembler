#include "../../include/get_value.h"
#include "../../include/line.h"
#include "../../include/parse_label.h"
#include "../../include/parse_line_type.h"
#include "../../include/parse_operation.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

TokenizedLine *tokenize(char *line, MetaAssembler meta_assembler) {
  int line_cursor = 0;

  TokenizedLine *tokenized_line = malloc(sizeof(TokenizedLine));
  if (tokenized_line == NULL) {
    printf("Failed to allocate memory for parsed_line\n");
    exit(EXIT_FAILURE);
  }

  skip_white_spaces(line, &line_cursor);
  if (is_comment(line)) {
    printf("Comment line\n");
    free(tokenized_line);
    return NULL;
  }

  tokenized_line->label = parse_label(line, &line_cursor);
  tokenized_line->type = parse_operation(line, &line_cursor);
  tokenized_line->value = get_value(line, &line_cursor);
  tokenized_line->line = rtrim(line);
  return tokenized_line;
}
