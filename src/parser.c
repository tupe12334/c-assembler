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

  parsed_line.type = parse_operation(line, &line_cursor);
  /*
    TODO check if there is : so there is label
    TODO check if its a operation or instuction line
   */
  exit(EXIT_FAILURE);
}
