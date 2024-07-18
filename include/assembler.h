#pragma once
#include "utils.h"
#include <stdio.h>

typedef const string Instruction;

enum AssemblerPase { PRE_MACRO, FIRST_RUN, SECOND_RUN };

typedef struct {
  enum AssemblerPase pase;
} MetaAssembler;

void assemble(FILE *assembly_file, File_Meta file_meta,
              MetaAssembler meta_assembler);
