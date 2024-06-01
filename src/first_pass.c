#include "../include/constants.h"
#include "../include/line.h"
#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>

void first_pass_handler(FILE *post_macro_file, MetaAssembler meta_assembler) {
  char line[MAX_LINE_LENGTH];
  ParsedLine *parsed_line;

  while (fgets(line, sizeof(line), post_macro_file)) {
    parsed_line = parse_line(line, meta_assembler);
  }
  free(parsed_line);
}
