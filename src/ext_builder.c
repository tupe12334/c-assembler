#include "../include/file_builders.h"
#include "../include/file_utils.h"
#include "../include/utils.h"
#include <stdio.h>

void ext_builder(Program *program, string filename) {
  string ext_filename = str_append(filename, ".ext");
  if (safe_strlen(program->externals) == 0) {
    return;
  }
  write_file(ext_filename, program->externals);
}
