#include "../include/line.h"
#include <string.h>

#define MACRO_DECLARATION "macr"
#define MACRO_END "endmacr"

unsigned short int is_macro_declaration_start(char *type) {
  return strcmp(type, MACRO_DECLARATION);
}

unsigned short int is_macro_declaration_end(char *type) {
  return strcmp(type, MACRO_END);
}