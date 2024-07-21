#pragma once
#include "assembler.h"
#include "dictionary.h"
#include "dynamic_array.h"
#include "line.h"
#include "program.h"

void line_handler(Program *program, Dictionary *label_table,
                  ParsedLine *parsed_line, MetaAssembler *meta_assembler);
void handle_operation(Program *program, Dictionary *label_table,
                      ParsedLine *parsed_line);
void handle_instructions(Program *program, Dictionary *label_table,
                         ParsedLine *parsed_line);
