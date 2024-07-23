#pragma once
#include "bool.h"
#include "dynamic_array.h"
#include "string.h"
#include <stdio.h>
#include <stdlib.h>
#define DYNAMIC_ARRAY_DATA_TYPE int

typedef struct {
  DynamicArray *darray;
  int data_lines;
  int code_lines;
  string externals;
} Program;

int program_code_lines(Program *program);
int program_data_lines(Program *program);
void program_append(Program *program, array_data decimal_value, bool is_data);
void program_init(Program *program);
size_t program_size(Program *program);
void append_externals(Program *program, string line);
