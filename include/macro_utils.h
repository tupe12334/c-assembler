#pragma once
#include "string.h"
#include <stdio.h>
unsigned short int is_macro_declaration_start(string line);
unsigned short int is_macro_declaration_end(string type);
FILE *fetch_postmacro_file(string filename);
