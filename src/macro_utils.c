#include "../include/constants.h"
#include "../include/parser.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MACRO_DECLARATION "macr"
#define MACRO_REGEX "(^|[^[:alnum:]_])macr([^[:alnum:]_]|$)"

unsigned short int is_macro_declaration_start(char *line) {
  regex_t regex;
  unsigned short int answer = 0;
  int reti;

  reti = regcomp(&regex, MACRO_REGEX, REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    exit(EXIT_FAILURE);
  }

  reti = regexec(&regex, line, 0, NULL, 0);

  if (!reti) {
    answer = 1;
  }

  regfree(&regex);
  return answer;
}