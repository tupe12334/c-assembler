#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/program.h"
#include "../../../include/string.h"
#include "../../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_data(Program *program, ParsedLine *parsed_line) {
  string token;
  token = strtok(parsed_line->tokens.value, ",");

  while (token != NULL) {
    string trimmed_token = trim(token);
    int value = atoi(trimmed_token);
    program_append(program, value, true);
    token = strtok(NULL, ",");
  }

  free(token);
  token = NULL;
}
