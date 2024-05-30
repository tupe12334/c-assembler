#include "../include/macros_handler.h"
#include "../include/utils.h"
#include <stdio.h>

void assemble(FILE *assembly_file, File_Meta file_meta) {
  macros_handler(assembly_file, file_meta.filename);
  /*
  int IC = 0;
  int DC = 0;
  */
}
