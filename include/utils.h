#pragma once
void skip_white_spaces(char *line, int *line_cursor);

int safe_strlen(const char *string);

typedef struct {
  char *filename;
} File_Meta;

int array_length(char **array);

unsigned short int is_comment(char *line);
unsigned short int is_line_empty(char *line);

unsigned short int get_operator_index(char *opcode);
