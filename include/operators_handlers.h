#pragma once
#include "constants.h"
#include "dynamic_array.h"
#include "line.h"

int common_handler(DynamicArray *program, OperatorLine *operator_line);
void handle_operands(DynamicArray *program, OperatorLine *operator_line);
#pragma region Operand handlers
int handler_register_operand(Operand *operand, enum OperandSide side);
int handle_label_operand(Operand *operand, enum OperandSide side);
#pragma endregion
void valid_jsr_operands(OperatorLine *operator_line);
void valid_add_operands(OperatorLine *operator_line);
void valid_prn_operands(OperatorLine *operator_line);
