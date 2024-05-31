#include "../include/constants.h"
#include "../include/instructions_list.h"
#include "../include/line.h"
#include "../include/op_codes.h"
#include "../include/utils.h"
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

/**
This function runs on the op_code object "name" values and on the instructions
array and compare if the operator is known.
*/
unsigned short int is_known_operator(char operator[]) {

  int i;

  for (i = 0; i < INSTRUCTIONS_LIST_SIZE; i++) {
    if (strcmp(operator, instructions[i]) == 0) {
      return TRUE;
    }
  }

  for (i = 0; i < OP_CODES_LENGTH; i++) {
    if (strcmp(operator, op_codes[i].name) == 0) {
      return TRUE;
    }
  }

  return FALSE;
}

void incase_line_counter(unsigned long int *LC) {
  *LC += 1;
  return;
}

unsigned short int is_comment(char *line) { return line[0] == ';'; }
unsigned short int is_line_empty(char *line) {
  int i;
  for (i = 0; i < strlen(line); i++) {
    if (line[i] != ' ' && line[i] != '\n' && line[i] != '\t') {
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
