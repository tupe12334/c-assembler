#pragma once
#include "string.h"
void skip_white_spaces(string line, int *line_cursor);

int safe_strlen(const string string);

typedef struct {
  string filename;
} File_Meta;

int array_length(string *array);

unsigned short int is_comment(string line);
unsigned short int is_line_empty(string line);

unsigned short int get_operator_index(string opcode);
