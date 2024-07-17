#include "../../include/bool.h"
#include "../../include/constants.h"
#include "../../include/is_instruction.h"
#include "../../include/meta_assembler.h"
#include "../../include/op_codes.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <string.h>

/**
This function runs on the op_code object "name" values and on the instructions
array and compare if the operator is known.
*/
bool is_known_operator(char command[], MetaAssembler meta_assembler) {
  int i;
  int op_code_length = get_op_codes_length();

  if (is_instruction(meta_assembler, command) == true) {
    return true;
  }

  for (i = 0; i < op_code_length; i++) {
    char *op_code = get_op_codes()[i];
    if (strcmp(command, op_code) == 0) {
      return true;
    }
  }

  return false;
}
