#pragma once
#include "constants.h"
#include "dynamic_array.h"
#include "line.h"

int common_handler(DynamicArray *program, OperatorLine *operator_line);
int handler_register_operand(Operand *operand, enum OperandSide side);
void handle_operands(DynamicArray *program, OperatorLine *operator_line);

void add_operator_handler(DynamicArray *program, OperatorLine *operator_line);
void prn_operator_handler(DynamicArray *program, OperatorLine *operator_line);
void jsr_operator_handler(DynamicArray *program, OperatorLine *operator_line);