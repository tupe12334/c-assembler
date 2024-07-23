#include "../include/assembler.h"
#include "../include/constants.h"
#include "../include/dictionary.h"
#include "../include/dynamic_array.h"
#include "../include/file_builders.h"
#include "../include/macro_utils.h"
#include "../include/macros_handler.h"
#include "../include/pass_handler.h"
#include "../include/program.h"
#include "../include/types.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>

void assemble(FILE *assembly_file, File_Meta file_meta,
              MetaAssembler *meta_assembler) {
  FILE *post_macro_file;
  Program *setup_program;
  Dictionary *label_table;
  Program *program;
  meta_assembler->pase = PRE_MACRO;
  macros_handler(assembly_file, file_meta.filename);
  post_macro_file = fetch_postmacro_file(file_meta.filename);
  setup_program = malloc(sizeof(Program));
  program_init(setup_program);
  puts("Fetched file post macro");

  label_table = create_dictionary();

  meta_assembler->pase = FIRST_RUN;
  pass_handler(setup_program, post_macro_file, label_table, meta_assembler);

  free(setup_program);
  setup_program = NULL;

  puts("Finished the first run");
  puts(COMMENT_LINE_BREAK);

  meta_assembler->pase = SECOND_RUN;

  program = malloc(sizeof(Program));
  program_init(program);
  pass_handler(program, post_macro_file, label_table, meta_assembler);
  ob_builder(program, file_meta.filename);
  ext_builder(program, file_meta.filename);
  ent_builder(program, file_meta.filename);
}
