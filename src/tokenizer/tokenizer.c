#include "../../include/get_value.h"
#include "../../include/line.h"
#include "../../include/parse_label.h"
#include "../../include/parse_line_type.h"
#include "../../include/parse_operation.h"
#include "../../include/string.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

TokenizedLine *tokenize(string line) {
  int line_cursor = 0;

  TokenizedLine *tokenized_line = malloc(sizeof(TokenizedLine));
  if (tokenized_line == NULL) {
    fprintf(stderr, "Failed to allocate memory for parsed_line\n");
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
  /* This is for removing the newline at the end of the line */
  tokenized_line->line = rtrim(line);
  return tokenized_line;
}
