#include "../../include/constants.h"
#include "../../include/file_utils.h"
#include "../../include/line.h"
#include "../../include/types.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MACRO_DECLARATION "macr"
#define MACRO_END "endmacr"

unsigned short int is_macro_declaration_start(char *type) {
  return strcmp(type, MACRO_DECLARATION);
}

unsigned short int is_macro_declaration_end(char *type) {
  return strcmp(type, MACRO_END);
}

unsigned short int is_comment(char *line) { return line[0] == ';'; }
unsigned short int is_line_empty(char *line) {
  int i;
  for (i = 0; i < strlen(line); i++) {

    if (isspace(line[i]) && line[i] != '\n' && line[i] != '\t') {
      return 0;
    }
  }
  return 1;
}

char *append_file_ext(char *filename, char *extention) {
  char *new_filename =
      (char *)malloc((strlen(filename) + strlen(extention) + 1) * sizeof(char));
  strcpy(new_filename, filename);
  strcat(new_filename, extention);
  return new_filename;
}

FILE *fetch_postmacro_file(char *filename) {
  return fetch_file(append_file_ext(filename, ".am"));
}
