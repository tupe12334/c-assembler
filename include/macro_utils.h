#pragma once
unsigned short int is_macro_declaration_start(char *line);
unsigned short int is_macro_declaration_end(char *type);
unsigned short int is_known_operator(char op[]);
void incase_line_counter(unsigned long int *LC);
char *append_file_ext(char *filename, char *extention);
