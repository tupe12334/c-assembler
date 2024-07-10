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

enum AddressMethod { ABSOLUTE = 4, RELOCATABLE = 2, EXTERNAL = 1 };

enum AddressType {
  NUMBER = 1,
  LABEL = 2,
  REGISTER_VALUE = 4,
  REGISTER_ADDRESS = 8,
};

typedef struct {
  char *value;
  enum AddressType address_type;
  enum AddressMethod address_method;
} Operand;

typedef struct {
  ParsedLine *parsed_line;
  unsigned short int opcode;
  Operand *operand_src;
  Operand *operand_dst;
} OperatorLine;
