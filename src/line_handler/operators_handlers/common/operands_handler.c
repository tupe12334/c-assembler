#include "../../../../include/assembler.h"
#include "../../../../include/bool.h"
#include "../../../../include/dictionary.h"
#include "../../../../include/line.h"
#include "../../../../include/operators_handlers.h"
#include "../../../../include/program.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int handle_operand(Program *program, Operand *operand, Dictionary *label_table,
                   enum OperandSide side, enum AssemblerPase pase) {
  int binary_code = 0;
  if (operand == NULL) {
    fprintf(stderr, "Invalid operand\n");
    exit(EXIT_FAILURE);
  }
  switch (operand->address_type) {
  case NUMBER:
    binary_code += ABSOLUTE;
    binary_code += handle_number_operand(operand, side);
    break;
  case LABEL:
    if (pase == FIRST_RUN) {
      break;
    }
    binary_code = handle_label_operand(program, operand, label_table, side);
    break;
  case REGISTER_VALUE:
  case REGISTER_ADDRESS:
    binary_code += ABSOLUTE;
    binary_code += handler_register_operand(operand, side);
    break;
  }

  return binary_code;
}

void handle_operands(Program *program, Dictionary *label_table,
                     OperatorLine *operator_line, enum AssemblerPase pase) {
  Bool is_have_src = operator_line->operand_src != NULL;
  Bool is_have_dst = operator_line->operand_dst != NULL;

  if (is_have_dst && is_have_src) {
    Bool is_src_register =
        operator_line->operand_src->address_type == REGISTER_VALUE ||
        operator_line->operand_src->address_type == REGISTER_ADDRESS;

    Bool is_dst_register =
        operator_line->operand_dst->address_type == REGISTER_VALUE ||
        operator_line->operand_dst->address_type == REGISTER_ADDRESS;

    Bool is_both_registers = is_dst_register && is_src_register;

    if (is_both_registers) {
      int binary_code = ABSOLUTE;
      binary_code += handler_register_operand(operator_line->operand_dst, DST);
      binary_code += handler_register_operand(operator_line->operand_src, SRC);
      program_append(program, binary_code, false);
      return;
    }
  }

  if (is_have_src) {
    int binary_code = handle_operand(program, operator_line->operand_src,
                                     label_table, SRC, pase);
    program_append(program, binary_code, false);
  }
  if (is_have_dst) {
    int binary_code = handle_operand(program, operator_line->operand_dst,
                                     label_table, DST, pase);
    program_append(program, binary_code, false);
  }
}
