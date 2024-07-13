
#include <stdio.h>
#include <stdlib.h>

FILE *fetch_file(char *full_file_name) {
  FILE *file;
  file = fopen(full_file_name, "r");

  if (file == NULL) {
    fprintf(stderr, "File %s does not exist\n", full_file_name);
    exit(EXIT_FAILURE);
  }

  return file;
}

void write_file(char *filename, char *content) {
  FILE *file;
  file = fopen(filename, "w");

  if (file == NULL) {
    fprintf(stderr, "File %s does not exist\n", filename);
    exit(EXIT_FAILURE);
  }

  fprintf(file, "%s", content);
  fclose(file);

  return;
}

void append_to_file(char *filename, char *content) {
  FILE *file;
  file = fopen(filename, "a");

  if (file == NULL) {
    fprintf(stderr, "File %s does not exist\n", filename);
    exit(EXIT_FAILURE);
  }

  fprintf(file, "%s\n", content);
  fclose(file);

  return;
}

void reset_file(char *filename) {
  write_file(filename, "");
  return;
}
