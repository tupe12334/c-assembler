#include "../../../../include/constants.h"
#include "../../../../include/dictionary.h"
#include "../../../../include/line.h"
#include "../../../../include/regex.h"
#include <stdio.h>
#include <stdlib.h>

int handle_label_operand(Operand *operand, Dictionary *label_table,
                         enum OperandSide side) {
  string lookup_value;
  lookup_value = lookup(label_table, operand->value);
  if (lookup_value == NULL) {
    // TODO if not finding the label throw
    return 0;
  }
  unsigned int address_int = atoi(lookup_value) + IC_STARTING_NUMBER;

  free(lookup_value);
  lookup_value = NULL;
  return address_int << 3;
}
