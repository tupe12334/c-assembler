#pragma once
#include "utils.h"
#include <stdio.h>

typedef struct {
  const char *name;
  const char *opcode;
} OpCode;

typedef const char *Instruction;

enum AssemblerPase { PRE_MACRO, FIRST_RUN, SECOND_RUN };

typedef struct {
  const OpCode *op_codes;
  const Instruction *instructions;
  enum AssemblerPase pase;
} MetaAssembler;

void assemble(FILE *assembly_file, File_Meta file_meta,
              MetaAssembler meta_assembler);
