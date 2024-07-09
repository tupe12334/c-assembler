#include "../../include/line.h"
#include "../../include/regex.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OPERAND_REGEX "^([^,\\s]+)"

char *get_first_operand(char *value) {
  char *first_operand = extract_word(value, OPERAND_REGEX);
  return first_operand;
}
char *get_second_operand(char *operand_a, char *value) {
  int operand_a_length = safe_strlen(operand_a) + 1;
  int length = safe_strlen(value) - operand_a_length;
  char *substring = malloc(length);

  if (is_line_empty(value + operand_a_length)) {
    puts("No second operand");
    return NULL;
  }
  strncpy(substring, ltrim(value + operand_a_length), length);
  char *second_operand = extract_word(substring, OPERAND_REGEX);
  return second_operand;
}

OperatorLine *parse_operator_line(ParsedLine *parsed_line) {
  OperatorLine *operator_line = malloc(sizeof(OperatorLine));
  operator_line->parsed_line = parsed_line;
  operator_line->operand_a = get_first_operand(parsed_line->tokens.value);
  operator_line->operand_b =
      get_second_operand(operator_line->operand_a, parsed_line->tokens.value);
  operator_line->opcode = get_operator_index(parsed_line->tokens.type);
  return operator_line;
}