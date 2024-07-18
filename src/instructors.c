#include "../include/assembler.h"

Instruction Instructors[] = {".data", ".string", ".entry", ".extern"};

Instruction *get_instructors(void) { return Instructors; }

const int get_instructors_length(void) {
  return sizeof(Instructors) / sizeof(Instructors[0]);
}
