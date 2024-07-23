#include "../../../include/constants.h"
#include "../../../include/dictionary.h"
#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/program.h"
#include <stdio.h>
#include <stdlib.h>

void handle_entries(Program *program, Dictionary *label_table,
                    ParsedLine *parsed_line) {

  string program_index = lookup(label_table, parsed_line->tokens.value);
  int int_address = atoi(program_index) + IC_STARTING_NUMBER;
  char address[4];
  sprintf(address, "%d", int_address);
  append_entry(program, parsed_line->tokens.value, address);

  return;
}