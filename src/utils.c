
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASSEMBLY_FILE_EXTENSION ".as"

char *parse_file_name(const char *file_name) {
  const unsigned short int file_name_length = strlen(file_name);
  const unsigned short int full_file_name_length =
      file_name_length + strlen(ASSEMBLY_FILE_EXTENSION) + 1;

  char *full_file_name = malloc(full_file_name_length);

  strcpy(full_file_name, file_name);

  strcat(full_file_name, ASSEMBLY_FILE_EXTENSION);

  return full_file_name;
}

FILE *fetch_file(char *full_file_name) {
  FILE *file;
  file = fopen(full_file_name, "r");

  if (file == NULL) {
    printf("File %s does not exist\n", full_file_name);
    exit(EXIT_FAILURE);
  }

  return file;
}
