
#include "../../include/constants.h"
#include "../../include/is_instruction.h"
#include "../../include/meta_assembler.h"
#include "../../include/utils.h"
#include <string.h>

/**
This function runs on the op_code object "name" values and on the instructions
array and compare if the operator is known.
*/
unsigned short int is_known_operator(char command[],
                                     MetaAssembler meta_assembler) {

  int i;

  if (is_instruction(meta_assembler, command) == TRUE) {
    return TRUE;
  }

  for (i = 0; i < OP_CODES_LENGTH; i++) {
    if (strcmp(command, meta_assembler.op_codes[i].name) == 0) {
      return TRUE;
    }
  }

  return FALSE;
}
