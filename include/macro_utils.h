#pragma once
#include <stdio.h>

unsigned short int is_macro_declaration_start(char *line);
unsigned short int is_macro_declaration_end(char *type);
FILE *fetch_postmacro_file(char *filename);
