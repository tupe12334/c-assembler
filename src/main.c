
#include "../include/assembler.h"
#include "../include/constants.h"
#include "../include/file_utils.h"
#include "../include/meta_assembler.h"
#include "../include/string.h"
#include "../include/utils.h"
#include "../include/validation.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, string argv[]) {
  int i;
  validate_input(argc, argv);
  for (i = 1; i < argc; i++) {
    FILE *file;
    string file_name = argv[i];
    File_Meta file_meta;
    MetaAssembler meta_assembler;

    string full_file_name = str_append(file_name, ASSEMBLY_FILE_EXTENSION);
    validate_file_access(full_file_name);

    file = fetch_file(full_file_name);

    file_meta.filename = file_name;
    meta_assembler = meta_assembler_init();
    assemble(file, file_meta, meta_assembler);

    fclose(file);
  }
  return EXIT_SUCCESS;
}
