#include "../include/line.h"
#include <string.h>

#define MACRO_DECLARATION "macr"

unsigned short int is_macro_declaration_start(ParsedLine *parsed_line) {
  return strcmp(parsed_line->type, MACRO_DECLARATION);
}
