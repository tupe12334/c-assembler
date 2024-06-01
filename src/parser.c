#include "../include/get_value.h"
#include "../include/line.h"
#include "../include/parse_label.h"
#include "../include/parse_line_type.h"
#include "../include/parse_operation.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

ParsedLine *parse_line(char *line, MetaAssembler meta_assembler) {
  int line_cursor = 0;
  ParsedLine *parsed_line = malloc(sizeof(ParsedLine));
  if (parsed_line == NULL) {
    printf("Failed to allocate memory for parsed_line\n");
    exit(EXIT_FAILURE);
  }

  if (is_comment(line)) {
    printf("Comment line\n");
    free(parsed_line);
    return NULL;
  }

  parsed_line->label = parse_label(line, &line_cursor);
  parsed_line->type = parse_operation(line, &line_cursor);
  parsed_line->value = get_value(line, &line_cursor);
  parsed_line->line = trim_last_char(line);
  parsed_line->line_type =
      command_to_line_type(parsed_line->type, meta_assembler);

  return parsed_line;
}
