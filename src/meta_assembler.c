#include "../include/assembler.h"

const Instruction instructions[] = {".data", ".string", ".entry", ".extern"};

MetaAssembler meta_assembler_init(void) {
  MetaAssembler meta_assembler;
  meta_assembler.instructions = instructions;
  meta_assembler.pase = PRE_MACRO;
  return meta_assembler;
}
