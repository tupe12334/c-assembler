#pragma once
#include <stdio.h>

unsigned short int is_macro_declaration_start(char *line);
unsigned short int is_macro_declaration_end(char *type);
char *append_file_ext(char *filename, char *extention);
FILE *fetch_postmacro_file(char *filename);
