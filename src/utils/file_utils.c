
#include "../../include/string.h"
#include <stdio.h>
#include <stdlib.h>

FILE *fetch_file(string full_file_name) {
  FILE *file;
  file = fopen(full_file_name, "r");

  if (file == NULL) {
    fprintf(stderr, "File %s does not exist\n", full_file_name);
    exit(EXIT_FAILURE);
  }

  return file;
}

void write_file(string filename, string content) {
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

void append_to_file(string filename, string content) {
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

void reset_file(string filename) {
  write_file(filename, "");
  return;
}
