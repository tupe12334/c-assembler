#include "../include/assembler.h"

const OpCode op_codes[] = {
    {"mov", "0000"}, {"cmp", "0001"}, {"add", "0010"}, {"sub", "0011"},
    {"lea", "0100"}, {"clr", "0101"}, {"not", "0110"}, {"inc", "0111"},
    {"dec", "1000"}, {"jmp", "1001"}, {"bne", "1010"}, {"red", "1011"},
    {"prn", "1100"}, {"jsr", "1101"}, {"rts", "1110"}, {"stop", "1111"}};
const Instruction instructions[] = {".data", ".string", ".entry", ".extern"};

MetaAssembler meta_assembler_init(void) {
  MetaAssembler meta_assembler;
  meta_assembler.op_codes = op_codes;
  meta_assembler.instructions = instructions;
  meta_assembler.pase = PRE_MACRO;
  return meta_assembler;
}
