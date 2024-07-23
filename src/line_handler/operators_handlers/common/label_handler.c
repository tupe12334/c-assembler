#include "../../../../include/constants.h"
#include "../../../../include/dictionary.h"
#include "../../../../include/line.h"
#include "../../../../include/program.h"
#include "../../../../include/regex.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int handle_label_operand(Program *program, Operand *operand,
                         Dictionary *label_table, enum OperandSide side) {
  string lookup_value;
  unsigned int address_int;

  lookup_value = lookup(label_table, operand->value);
  if (lookup_value == NULL) {
    exit(EXIT_FAILURE);
  }
  if (strcmp(lookup_value, EXTERNAL_LABEL_FLAG) == 0) {
    string line;
    int number_address = program_size(program);
    char temp_str[4];
    string address_str = malloc(strlen(temp_str) + 1);
    sprintf(temp_str, "%d", number_address + IC_STARTING_NUMBER);

    strcpy(address_str, temp_str);

    if (number_address < 999) {
      address_str = str_append("0", temp_str);
    }

    line = str_append(str_append(str_append(operand->value, " "), address_str),
                      "\n");

    append_externals(program, line);
    return EXTERNAL;
  }

  address_int = atoi(lookup_value) + IC_STARTING_NUMBER;

  free(lookup_value);
  lookup_value = NULL;
  return (address_int << 3) + RELOCATABLE;
}
