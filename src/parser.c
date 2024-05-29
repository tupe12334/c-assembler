#include "../include/get_value.h"
#include "../include/line.h"
#include "../include/parse_label.h"
#include "../include/parse_operation.h"
#include <stdio.h>
#include <stdlib.h>

unsigned short int is_comment(char *line) { return line[0] == ';'; }

struct Line *parse_line(char *line) {
  struct Line parsed_line;
  int line_cursor = 0;
  is_comment(line);
  if (is_comment(line)) {
    printf("Comment line\n");
    return NULL;
  }

  parsed_line.label = parse_label(line, &line_cursor);
  printf("Label: %s\n", parsed_line.label);
  printf("Cursor: %d\n", line_cursor);

  parsed_line.type = parse_operation(line, &line_cursor);
  printf("Type: %s\n", parsed_line.type);
  printf("Cursor: %d\n", line_cursor);

  parsed_line.value = get_value(line, &line_cursor);
  puts(parsed_line.value);
  printf("Value: %s\n", parsed_line.value);
  printf("Cursor: %d\n", line_cursor);
  /*
    TODO check if there is : so there is label
    TODO check if its a operation or instuction line
   */
  exit(EXIT_FAILURE);
}
