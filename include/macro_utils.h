#pragma once
#include <stdio.h>

unsigned short int is_macro_declaration_start(char *line);
unsigned short int is_macro_declaration_end(char *type);
void incase_line_counter(unsigned long int *LC);
char *append_file_ext(char *filename, char *extention);
FILE *fetch_postmacro_file(char *filename);
