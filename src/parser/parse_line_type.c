#include "../../include/constants.h"
#include "../../include/is_instruction.h"
#include "../../include/line.h"
#include "../../include/meta_assembler.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum LineType command_to_line_type(char *command,
                                   MetaAssembler meta_assembler) {
  int i;
  if (command == NULL) {
    return EMPTY;
  }

  if (command[0] == '.') {
    if (is_instruction(meta_assembler, command) == TRUE) {
      return INSTRUCTION;
    }
  }

  for (i = 0; i < OP_CODES_LENGTH; i++) {
    if (strcmp(command, meta_assembler.op_codes[i].name) == 0) {
      return OPERATION;
    }
  }

  if (meta_assembler.pase == PRE_MACRO) {
    return MACRO;
  }

  printf("Unknown command: %s\n", command);
  exit(EXIT_FAILURE);
}
