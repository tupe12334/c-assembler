#include "../../../include/dictionary.h"
#include "../../../include/operator_parser.h"
#include "../../../include/operators_handlers.h"
#include "../../../include/program.h"

void validate_operator(OperatorLine *operator_line) {
  switch (operator_line->opcode) {
  case 0:
    valid_mov_operands(operator_line);
    break;
  case 1:
    valid_cmp_operands(operator_line);
    break;
  case 2:
    valid_add_operands(operator_line);
    break;
  case 3:
    valid_sub_operands(operator_line);
    break;
  case 4:
    valid_lea_operands(operator_line);
    break;
  case 5:
    valid_clr_operands(operator_line);
    break;
  case 6:
    valid_not_operands(operator_line);
    break;
  case 7:
    valid_inc_operands(operator_line);
    break;
  case 8:
    valid_dec_operands(operator_line);
    break;
  case 9:
    valid_jmp_operands(operator_line);
    break;
  case 10:
    valid_bne_operands(operator_line);
    break;
  case 11:
    valid_red_operands(operator_line);
    break;
  case 12:
    valid_prn_operands(operator_line);
    break;
  case 13:
    valid_jsr_operands(operator_line);
    break;
  case 14:
    valid_rts_operands(operator_line);
    break;
  case 15:
    valid_stop_operands(operator_line);
    break;
  default:
    printf("Error in handle_operation: unknown operation type %s\n",
           operator_line->parsed_line->tokens.type);
    exit(EXIT_FAILURE);
    break;
  }
}

void handle_operation(Program *program, Dictionary *label_table,
                      ParsedLine *parsed_line, enum AssemblerPase pase) {
  OperatorLine *operator_line;
  int binary_code;
  operator_line = parse_operator_line(parsed_line);

  validate_operator(operator_line);
  binary_code = common_handler(operator_line);
  program_append(program, binary_code, false);

  handle_operands(program, label_table, operator_line, pase);
}
