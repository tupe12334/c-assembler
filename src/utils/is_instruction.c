#include "../../include/constants.h"
#include "../../include/instructors.h"
#include "../../include/meta_assembler.h"
#include <stdbool.h>
#include <string.h>

unsigned short int is_instruction(MetaAssembler meta_assembler, char *command) {
  int i;
  for (i = 0; i < get_instructors_length(); i++) {
    if (strcmp(command, get_instructors()[i]) == 0) {
      return true;
    }
  }
  return false;
}
