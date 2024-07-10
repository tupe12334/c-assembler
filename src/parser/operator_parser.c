#include "../../include/line.h"
#include "../../include/regex.h"
#include "../../include/utils.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum OperandSide { SRC, DST };

#define OPERAND_REGEX "^([^,\\s]+)"
#define SEC_OPERAND_REGEX ",(.*)"

enum AddressType get_address_type(char *operand) {
  if (operand[0] == '#') {
    return NUMBER;
  }
  if (operand[0] == "*") {
    return REGISTER_VALUE;
  }
  if (operand[0] == "r") {
    return REGISTER_ADDRESS;
  }
  return LABEL;
}

Operand *build_operand(OperatorLine *operator_line, enum OperandSide side) {
  char *value;
  switch (side) {
  case SRC:
    value = extract_word(operator_line->parsed_line->tokens.value,
                         SEC_OPERAND_REGEX);
    break;
  case DST:
    value =
        extract_word(operator_line->parsed_line->tokens.value, OPERAND_REGEX);
    break;
  }
  if (value == NULL) {
    return NULL;
  }
  Operand *operand = malloc(sizeof(Operand));
  operand->value = value;
  operand->address_type = get_address_type(operand->value);
  return operand;
}

void print_operator(OperatorLine *operator_line) {
  printf("Operator: (%s)", operator_line->parsed_line->tokens.type);
  printf(" DST: (%s)", operator_line->operand_dst->value);
  if (operator_line->operand_src != NULL) {
    printf(" SRC: (%s)", operator_line->operand_src->value);
  }
  printf("\n");
}

OperatorLine *parse_operator_line(ParsedLine *parsed_line) {
  OperatorLine *operator_line = malloc(sizeof(OperatorLine));
  operator_line->parsed_line = parsed_line;
  operator_line->operand_dst = build_operand(operator_line, DST);
  operator_line->operand_src = build_operand(operator_line, SRC);

  operator_line->opcode = get_operator_index(parsed_line->tokens.type);
  print_operator(operator_line);
  return operator_line;
}