#include "../../include/program.h"
#include "../../include/dynamic_array.h"
#include <stdio.h>

int program_data_lines(Program *array) { return array->data_lines; }

int program_code_lines(Program *array) { return array->code_lines; }

void program_init(Program *program) {
  program->darray = (DynamicArray *)malloc(sizeof(DynamicArray));
  darray_init(program->darray, 2);
  program->externals = "";
  program->entry = "";
  program->data_lines = 0;
  program->code_lines = 0;
}

void program_append(Program *program, array_data decimal_value, bool is_data) {
  is_data == true ? program->data_lines++ : program->code_lines++;
  darray_append(program->darray, decimal_value);
}

size_t program_size(Program *program) { return darray_size(program->darray); }

void append_externals(Program *program, string line) {
  printf("🔗 Appending to externals: %s\n", line);
  printf("🔗 Current externals: %s\n", program->externals);
  program->externals = str_append(program->externals, line);
}

void append_entry(Program *program, string label, string address) {
  program->entry =
      str_append(program->entry,
                 str_append(label, str_append(" ", str_append(address, "\n"))));
}