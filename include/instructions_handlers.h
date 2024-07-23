#include "dictionary.h"
#include "dynamic_array.h"
#include "line.h"
#include "program.h"

void handle_string(Program *program, ParsedLine *parsed_line);
void handle_data(Program *program, ParsedLine *parsed_line);
void handle_externals(Program *program, Dictionary *label_table,
                      ParsedLine *parsed_line);
