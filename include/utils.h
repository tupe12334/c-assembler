#pragma once

char *parse_file_name(const char *file_name);

void skip_white_spaces(char *line, int *line_cursor);

char *trim_last_char(char *string);

int safe_strlen(const char *string);
