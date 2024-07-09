#pragma once
#include "daynamic_array.h"
#include "line.h"

void line_handler(DynamicArray *program, ParsedLine *parsed_line);
void handle_operation(DynamicArray *program, ParsedLine *parsed_line);
