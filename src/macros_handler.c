#include "../include/constants.h"
#include "../include/macro_utils.h"
#include "../include/parser.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void macros_handler(FILE *assembly_file) {

  unsigned short int macro_recording = 0;

  /* Line counter */
  unsigned long int LC = 0;

  char line[MAX_LINE_LENGTH];

  while (fgets(line, sizeof(line), assembly_file)) {
    LC++;
    if (is_macro_declaration_start(line)) {
      macro_recording = 1;
      parse_line(line);
    }
  }
}
