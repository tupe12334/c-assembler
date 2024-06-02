#pragma once
#include "assembler.h"
#include "line.h"

ParsedLine *parse_line(TokenizedLine line, MetaAssembler meta_assembler);
