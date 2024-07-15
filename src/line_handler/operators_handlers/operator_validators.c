#include "../../../include/operator_validators.h"
#include "../../../include/line.h"

void valid_mov_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {0, 1, 2, 3};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_cmp_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {0, 1, 2, 3};
  unsigned short int valid_dst_address_codes[] = {0, 1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_add_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {0, 1, 2, 3};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_sub_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {0, 1, 2, 3};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_lea_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {1};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_clr_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_not_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_inc_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_dec_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_jmp_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_bne_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_red_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_prn_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {0, 1, 2, 3};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_jsr_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {1, 2};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_rts_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {-1};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
void valid_stop_operands(OperatorLine *operator_line) {
  unsigned short int valid_src_address_codes[] = {-1};
  unsigned short int valid_dst_address_codes[] = {-1};
  validate_operands(operator_line, valid_src_address_codes,
                    valid_dst_address_codes);
}
