#pragma once
#include "string.h"

enum LineType { EMPTY, OPERATION, INSTRUCTION, MACRO };

typedef struct {
  string label;
  string type;
  string value;
  string line;
} TokenizedLine;

typedef struct {
  TokenizedLine tokens;
  enum LineType line_type;
} ParsedLine;

enum AddressMethod { ABSOLUTE = 4, RELOCATABLE = 2, EXTERNAL = 1 };

enum AddressType {
  NUMBER = 1,
  LABEL = 2,
  REGISTER_VALUE = 4,
  REGISTER_ADDRESS = 8
};

typedef struct {
  string value;
  enum AddressType address_type;
} Operand;

typedef struct {
  ParsedLine *parsed_line;
  unsigned short int opcode;
  Operand *operand_src;
  Operand *operand_dst;
} OperatorLine;
