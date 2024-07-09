#pragma once

char *append_assembly_extension(const char *file_name);

void skip_white_spaces(char *line, int *line_cursor);

char *rtrim(char *string);

int safe_strlen(const char *string);

typedef struct {
  char *filename;
} File_Meta;

int array_length(char **array);

unsigned short int is_comment(char *line);
unsigned short int is_line_empty(char *line);

char *ltrim(char *s);
