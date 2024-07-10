#include "../include/dynamic_array.h"
#include "../include/file_utils.h"
#include "../include/string.h"
#include <stdio.h>
#include <stdlib.h>

void ob_builder(DynamicArray *program, char *filename) {
  int instruction_length = darray_code_lines(program);
  int data_length = darray_data_lines(program);
  char str_instruction_length[5];
  char str_data_length[5];

  sprintf(str_instruction_length, "%d", instruction_length);
  sprintf(str_data_length, "%d", data_length);

  char *file_title =
      str_append(str_append(str_instruction_length, " "), str_data_length);
  puts(file_title);
  write_file(str_append(filename, ".ob"), file_title);
}