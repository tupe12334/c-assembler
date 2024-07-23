#include "../include/file_builders.h"
#include "../include/file_utils.h"
#include "../include/utils.h"
#include <stdio.h>

void ent_builder(Program *program, string filename) {
  string ent_filename = str_append(filename, ".ent");
  if (safe_strlen(program->entry) == 0) {
    return;
  }
  write_file(ent_filename, program->entry);
}
