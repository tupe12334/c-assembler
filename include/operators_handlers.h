#pragma once
#include "constants.h"
#include "dynamic_array.h"
#include "line.h"
#include "program.h"

int common_handler(Program *program, OperatorLine *operator_line);
void handle_operands(Program *program, OperatorLine *operator_line);
#pragma region Operand handlers
int handler_register_operand(Operand *operand, enum OperandSide side);
int handle_label_operand(Operand *operand, enum OperandSide side);
int handle_number_operand(Operand *operand, enum OperandSide side);
#pragma endregion
void valid_mov_operands(OperatorLine *operator_line);
void valid_cmp_operands(OperatorLine *operator_line);
void valid_add_operands(OperatorLine *operator_line);
void valid_sub_operands(OperatorLine *operator_line);
void valid_lea_operands(OperatorLine *operator_line);
void valid_clr_operands(OperatorLine *operator_line);
void valid_not_operands(OperatorLine *operator_line);
void valid_inc_operands(OperatorLine *operator_line);
void valid_dec_operands(OperatorLine *operator_line);
void valid_jmp_operands(OperatorLine *operator_line);
void valid_bne_operands(OperatorLine *operator_line);
void valid_red_operands(OperatorLine *operator_line);
void valid_prn_operands(OperatorLine *operator_line);
void valid_jsr_operands(OperatorLine *operator_line);
void valid_rts_operands(OperatorLine *operator_line);
void valid_stop_operands(OperatorLine *operator_line);
