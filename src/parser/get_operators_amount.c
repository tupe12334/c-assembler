#include "../../include/assembler.h"
#include "../../include/constants.h"
#include "../../include/line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum Operators_amount get_operators_amount(char *command,
                                           MetaAssembler meta_assembler) {

  unsigned short int i;
  int op_code_index;
  for (i = 0; i < OP_CODES_LENGTH; i++) {
    if (strcmp(command, meta_assembler.op_codes[i].name) == 0) {
      op_code_index = i;
    }
  }

  switch (op_code_index) {
  case 0:
  case 1:
  case 2:
  case 3:
  case 4:
    return TWO;

  case 5:
  case 6:
  case 7:
  case 8:
  case 9:
  case 10:
  case 11:
  case 12:
  case 13:
    return ONE;

  case 14:
  case 15:
    return NONE;
  }

  printf("There was a bug in get_operators_amount with the value %s\n",
         command);
  exit(EXIT_FAILURE);
}