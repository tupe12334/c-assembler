#include <stdio.h>
#include <stdlib.h>

void validate_at_least_one_input(int argc) {
  if (argc < 2) {
    printf("Missing files for assembler\n");
    exit(1);
  }
}
void validate_input(int argc, char *argv[]) {
  validate_at_least_one_input(argc);
}
