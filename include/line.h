#pragma once

enum LineType { EMPTY, OPERATION, INSTRUCTION, MACRO };

enum Operators_amount { NONE, ONE, TWO };

typedef struct {
  char *label;
  char *type;
  char *value;
  char *line;
} TokenizedLine;

typedef struct {
  TokenizedLine tokens;
  enum LineType line_type;
  enum Operators_amount operators_amount;
} ParsedLine;

typedef struct {
  ParsedLine *parsed_line;
  unsigned short int opcode;
  char *operand_a;
  char *operand_b;
} OperatorLine;