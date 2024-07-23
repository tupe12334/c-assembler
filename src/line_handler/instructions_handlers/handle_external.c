#include "../../../include/constants.h"
#include "../../../include/dictionary.h"
#include "../../../include/dynamic_array.h"
#include "../../../include/line.h"
#include "../../../include/program.h"
#include <stdio.h>

void handle_externals(Program *program, Dictionary *label_table,
                      ParsedLine *parsed_line) {
  string value = parsed_line->tokens.value;
  insert(label_table, value, EXTERNAL_LABEL_FLAG);
  return;
}
