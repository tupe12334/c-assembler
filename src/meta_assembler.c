#include "../include/assembler.h"

MetaAssembler meta_assembler_init(void) {
  MetaAssembler meta_assembler;
  meta_assembler.pase = PRE_MACRO;
  return meta_assembler;
}
