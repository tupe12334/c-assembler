#pragma once
#include "assembler.h"
#include "dictionary.h"
#include "dynamic_array.h"
#include "program.h"
#include <stdio.h>

void first_pass_handler(Program *program, FILE *post_macro_file,
                        Dictionary *label_table, MetaAssembler meta_assembler);
