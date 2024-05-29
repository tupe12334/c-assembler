#include "../include/get_value.h"
#include "../include/line.h"
#include "../include/parse_label.h"
#include "../include/parse_operation.h"
#include <stdio.h>
#include <stdlib.h>

unsigned short int is_comment(char *line) { return line[0] == ';'; }

ParsedLine *parse_line(char *line) {
  ParsedLine *parsed_line = malloc(sizeof(ParsedLine));
  if (parsed_line == NULL) {
    printf("Failed to allocate memory for parsed_line\n");
    return NULL;
  }
  int line_cursor = 0;
  if (is_comment(line)) {
    printf("Comment line\n");
    free(parsed_line);
    return NULL;
  }

  parsed_line->label = parse_label(line, &line_cursor);
  printf("Label: %s\n", parsed_line->label);
  printf("Cursor: %d\n", line_cursor);

  parsed_line->type = parse_operation(line, &line_cursor);
  printf("Type: %s\n", parsed_line->type);
  printf("Cursor: %d\n", line_cursor);

  parsed_line->value = get_value(line, &line_cursor);
  puts(parsed_line->value);
  printf("Value: %s\n", parsed_line->value);
  printf("Cursor: %d\n", line_cursor);

  return parsed_line;
}
