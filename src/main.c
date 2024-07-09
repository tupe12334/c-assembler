
#include "../include/assembler.h"
#include "../include/file_utils.h"
#include "../include/meta_assembler.h"
#include "../include/utils.h"
#include "../include/validation.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int i;
  validate_input(argc, argv);
  for (i = 1; i < argc; i++) {
    FILE *file;
    char *file_name = argv[i];
    File_Meta file_meta;
    MetaAssembler meta_assembler;

    char *full_file_name = append_assembly_extension(file_name);
    validate_file_access(full_file_name);

    file = fetch_file(full_file_name);

    file_meta.filename = file_name;
    meta_assembler = meta_assembler_init();
    assemble(file, file_meta, meta_assembler);

    fclose(file);
  }
  return EXIT_SUCCESS;
}
