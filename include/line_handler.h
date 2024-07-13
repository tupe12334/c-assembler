#pragma once
#include "dynamic_array.h"
#include "line.h"

void line_handler(DynamicArray *program, ParsedLine *parsed_line);
void handle_operation(DynamicArray *program, ParsedLine *parsed_line);
void handle_instructions(DynamicArray *program, ParsedLine *parsed_line);
