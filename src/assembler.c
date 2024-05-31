#include "../include/macro_utils.h"
#include "../include/macros_handler.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>

void assemble(FILE *assembly_file, File_Meta file_meta) {
  FILE *post_macro_file;
  macros_handler(assembly_file, file_meta.filename);
  post_macro_file = fetch_postmacro_file(file_meta.filename);
  counter IC = 0;
  counter DC = 0;
}
