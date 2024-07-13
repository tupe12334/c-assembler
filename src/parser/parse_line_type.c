#include "../../include/constants.h"
#include "../../include/is_instruction.h"
#include "../../include/line.h"
#include "../../include/meta_assembler.h"
#include "../../include/op_codes.h"
#include <stdbool.h>
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
    if (is_instruction(meta_assembler, command) == true) {
      return INSTRUCTION;
    }
  }

  for (i = 0; i < get_op_codes_length(); i++) {
    if (strcmp(command, get_op_codes()[i]) == 0) {
      return OPERATION;
    }
  }

  if (meta_assembler.pase == PRE_MACRO) {
    return MACRO;
  }

  fprintf(stderr, "Unknown command: %s\n", command);
  exit(EXIT_FAILURE);
}
