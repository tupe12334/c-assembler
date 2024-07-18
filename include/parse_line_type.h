#pragma once
#include "assembler.h"
#include "line.h"

enum LineType command_to_line_type(string command,
                                   MetaAssembler meta_assembler);
