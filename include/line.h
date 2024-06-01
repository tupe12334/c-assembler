#pragma once

enum LineType { EMPTY, OPERATION, INSTRUCTION, MACRO };

typedef struct {
  char *label;
  char *type;
  char *value;
  char *line;
  enum LineType line_type;
} ParsedLine;
