#include "../../include/constants.h"
#include "../../include/meta_assembler.h"
#include <stdbool.h>
#include <string.h>

unsigned short int is_instruction(MetaAssembler meta_assembler, char *command) {
  int i;
  for (i = 0; i < INSTRUCTIONS_LIST_SIZE; i++) {
    if (strcmp(command, meta_assembler.instructions[i]) == 0) {
      return true;
    }
  }
  return false;
}