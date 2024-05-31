#pragma once
#define TRUE 1
#define FALSE 0

char *parse_file_name(const char *file_name);

void skip_white_spaces(char *line, int *line_cursor);

char *trim_last_char(char *string);

int safe_strlen(const char *string);

typedef struct {
  char *filename;
} File_Meta;

unsigned short int is_comment(char *line);
unsigned short int is_line_empty(char *line);
