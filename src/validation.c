#include "../include/errors.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void validate_at_least_one_input(int argc) {
  if (argc < 2) {
    fprintf(stderr, MISSING_AS_FILE_ERROR);
    exit(MISSING_AS_FILE_ERROR_CODE);
  }
}
void validate_file_access(string full_file_name) {
  if (access(full_file_name, F_OK) != 0) {
    fprintf(stderr, "File %s does not exist\n", full_file_name);
    exit(EXIT_FAILURE);
  }
  if (access(full_file_name, R_OK) != 0) {
    fprintf(stderr, "File %s is not readable\n", full_file_name);
    exit(EXIT_FAILURE);
  }
  return;
}

void validate_input(int argc, string argv[]) {
  validate_at_least_one_input(argc);
  return;
}
