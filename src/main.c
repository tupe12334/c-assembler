
#include "../include/assembler.h"
#include "../include/utils.h"
#include "../include/validation.h"
#include <stdio.h>

int main(int argc, char *argv[]) {
  int i;
  validate_input(argc, argv);
  for (i = 1; i < argc; i++) {
    FILE *file;
    char *file_name = argv[i];

    char *full_file_name = parse_file_name(file_name);

    file = fetch_file(full_file_name);

    assemble(file);

    fclose(file);
  }
  return 0;
}