#include "../include/constants.h"
#include "../include/dynamic_array.h"
#include "../include/file_utils.h"
#include "../include/number.h"
#include "../include/string.h"
#include <stdio.h>
#include <stdlib.h>

char *build_line(int index, int value) {
  int display_index = index + IC_STARTING_NUMBER;
  char *index_str;
  sprintf(index_str, "%d", display_index);
  if (display_index < 1000) {
    index_str = str_append("0", index_str);
  }
  return str_append(
      "\n", str_append((index_str), str_append(" ", decimal_to_octal(value))));
}

void ob_builder(DynamicArray *program, char *filename) {
  char *object_filename = str_append(filename, ".ob");
  int instruction_length = darray_code_lines(program);
  int data_length = darray_data_lines(program);
  char str_instruction_length[5];
  char str_data_length[5];

  sprintf(str_instruction_length, "%d", instruction_length);
  sprintf(str_data_length, "%d", data_length);

  char *file_title =
      str_append(str_append(str_instruction_length, " "), str_data_length);
  write_file(object_filename, file_title);

  for (int i = 0; i < program->size; i++) {
    int value = program->data[i];
    append_to_file(object_filename, build_line(i, value));
  }
}