#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/utils.h"
#include <stdio.h>
#include <string.h>

void handle_data(DynamicArray *program, ParsedLine *parsed_line) {
  printf("Got into .data line %s\n", parsed_line->tokens.line);
  char *token;
  token = strtok(parsed_line->tokens.value, ",");

  while (token != NULL) {
    char *trimmed_token = rtrim(ltrim(token));

    int value = atoi(trimmed_token);

    darray_append(program, value, true);
    token = strtok(NULL, ",");
  }
}