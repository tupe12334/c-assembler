#include "../../include/constants.h"
#include "../../include/file_utils.h"
#include "../../include/line.h"
#include "../../include/string.h"
#include "../../include/types.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MACRO_DECLARATION "macr"
#define MACRO_END "endmacr"

unsigned short int is_macro_declaration_start(string type) {
  return strcmp(type, MACRO_DECLARATION);
}

unsigned short int is_macro_declaration_end(string type) {
  return strcmp(type, MACRO_END);
}

unsigned short int is_comment(string line) { return line[0] == ';'; }
unsigned short int is_line_empty(string line) {
  int i;
  for (i = 0; i < strlen(line); i++) {

    if (isspace(line[i]) && line[i] != '\n' && line[i] != '\t') {
      return 0;
    }
  }
  return 1;
}

FILE *fetch_postmacro_file(string filename) {
  return fetch_file(str_append(filename, ".am"));
}
