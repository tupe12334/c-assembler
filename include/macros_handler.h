#pragma once
#include "assembler.h"
#include <stdio.h>

void macros_handler(FILE *assembly_file, MetaAssembler meta_assembler,
                    string filename);
