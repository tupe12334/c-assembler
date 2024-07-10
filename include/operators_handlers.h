#pragma once
#include "dynamic_array.h"
#include "line.h"

void add_operator_handler(DynamicArray *program, OperatorLine *operator_line);
void prn_operator_handler(DynamicArray *program, OperatorLine *operator_line);
void jsr_operator_handler(DynamicArray *program, OperatorLine *operator_line);