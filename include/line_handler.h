#pragma once
#include "dynamic_array.h"
#include "line.h"
#include "program.h"

void line_handler(Program *program, ParsedLine *parsed_line);
void handle_operation(Program *program, ParsedLine *parsed_line);
void handle_instructions(Program *program, ParsedLine *parsed_line);
