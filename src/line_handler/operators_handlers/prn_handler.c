#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include <stdio.h>

unsigned int appendZeros(unsigned int num, int x) { return num << x; }

void prn_operator_handler(DynamicArray *program, OperatorLine *operator_line) {
  int binary_code = 0;
  unsigned short op_code = operator_line->opcode;
  int op_code_binary_section = op_code << 11;
  binary_code += op_code_binary_section;
  darray_append(program, binary_code);
  darray_print(program);
}