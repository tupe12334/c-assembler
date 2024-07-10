#include "../include/assembler.h"
#include "../include/constants.h"
#include "../include/dynamic_array.h"
#include "../include/file_builders.h"
#include "../include/first_pass.h"
#include "../include/macro_utils.h"
#include "../include/macros_handler.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>

void assemble(FILE *assembly_file, File_Meta file_meta,
              MetaAssembler meta_assembler) {
  FILE *post_macro_file;
  counter IC = IC_STARTING_NUMBER;
  counter DC = 0;
  macros_handler(assembly_file, meta_assembler, file_meta.filename);
  post_macro_file = fetch_postmacro_file(file_meta.filename);
  DynamicArray *program = malloc(sizeof(DynamicArray));
  darray_init(program, 2);
  puts("Fetched file post macro");
  meta_assembler.pase = FIRST_RUN;
  first_pass_handler(program, post_macro_file, meta_assembler);
  ob_builder(program, file_meta.filename);
  darray_print(program);
}
