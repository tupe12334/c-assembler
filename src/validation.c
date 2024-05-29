
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void validate_at_least_one_input(int argc) {
  if (argc < 2) {
    printf("Missing files for assembler\n");
    exit(1);
  }
}
void validate_files_existing(int argc, char *argv[]) {
  int i;
  for (i = 1; i < argc; i++) {

    char *file_name = argv[i];

    const char *full_file_name = parse_file_name(file_name);

    if (access(full_file_name, F_OK) != 0) {
      printf("File %s does not exist\n", full_file_name);
      exit(1);
    }
    if (access(full_file_name, R_OK) != 0) {
      printf("File %s is not readable\n", full_file_name);
      exit(1);
    }
  }
}

void validate_input(int argc, char *argv[]) {
  validate_at_least_one_input(argc);
  validate_files_existing(argc, argv);
}
