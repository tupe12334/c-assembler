#include "../include/constants.h"
#include "../include/dynamic_array.h"
#include "../include/file_utils.h"
#include "../include/number.h"
#include "../include/string.h"
#include <stdio.h>
#include <stdlib.h>

string format_index(int index) {
  int display_index = index + IC_STARTING_NUMBER;
  string index_str;
  sprintf(index_str, "%d", display_index);
  if (display_index < 1000) {
    index_str = str_append("0", index_str);
  }
  return index_str;
}

char *format_value(int value) {
  char *value_str;
  int i;
  if (value < 0) {
    char *binary = decimal_to_binary(value);
    value_str = binary_to_octal(binary);
    free(binary);
    binary = NULL;
  } else {
    value_str = decimal_to_octal(value);
  }

  i = 0;
  while (value_str[i] > 5) {
    i++;
  }
  for (; i < 5; i++) {
    value_str = str_append("0", value_str);
  }
  return value_str;
}
char *build_line(int index, int value) {
  char *formatted_index = format_index(index);
  char *formatted_value = format_value(value);
  char *line = str_append(formatted_index, str_append(" ", formatted_value));
  return line;
}

void ob_builder(DynamicArray *program, char *filename) {
  int i;
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
  append_to_file(object_filename, "");
  for (i = 0; i < program->size; i++) {
    int value = program->data[i];
    char *line = build_line(i, value);
    append_to_file(object_filename, line);
  }
}
