#pragma once
#include "assembler.h"
#include "dynamic_array.h"
#include "program.h"
#include <stdio.h>

void first_pass_handler(Program *program_array, FILE *post_macro_file,
                        MetaAssembler meta_assembler);
