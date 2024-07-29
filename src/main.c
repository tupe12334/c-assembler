
#include "../include/assembler.h"
#include "../include/constants.h"
#include "../include/file_utils.h"
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
    MetaAssembler *meta_assembler;
    string full_file_name;

    meta_assembler = (MetaAssembler *)malloc(sizeof(MetaAssembler));

    full_file_name = str_append(file_name, ASSEMBLY_FILE_EXTENSION);
    validate_file_access(full_file_name);

    file = fetch_file(full_file_name);

    file_meta.filename = file_name;
    assemble(file, file_meta, meta_assembler);
    puts("Assembled the file");
    fclose(file);
  }
  return EXIT_SUCCESS;
}
