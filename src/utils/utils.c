
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSEMBLY_FILE_EXTENSION ".as"

char *append_assembly_extension(const char *file_name) {
  const unsigned short int file_name_length = strlen(file_name);
  const unsigned short int full_file_name_length =
      file_name_length + strlen(ASSEMBLY_FILE_EXTENSION) + 1;

  char *full_file_name = malloc(full_file_name_length);

  strcpy(full_file_name, file_name);

  strcat(full_file_name, ASSEMBLY_FILE_EXTENSION);

  return full_file_name;
}

void skip_white_spaces(char *line, int *line_cursor) {
  while (line[*line_cursor] == ' ' || line[*line_cursor] == '\t') {
    *line_cursor = *line_cursor + 1;
  }
}

char *rtrim(const char *str) {
  int n = strlen(str);

  // Find the position of the last non-whitespace character
  while (n > 0 && isspace((unsigned char)str[n - 1])) {
    n--;
  }

  // Allocate memory for the new trimmed string
  char *trimmed = (char *)malloc(n + 1);
  if (trimmed == NULL) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  // Copy the trimmed portion of the string to the new string
  strncpy(trimmed, str, n);
  trimmed[n] = '\0'; // Null-terminate the new string

  return trimmed;
}

char *ltrim(char *s) {
  while (isspace((unsigned char)*s))
    s++;
  return s;
}

int safe_strlen(const char *string) {
  return string != NULL ? strlen(string) : 0;
}

int array_length(char **array) {
  int i = 0;
  while (array[i] != NULL) {
    i++;
  }
  return i;
}
