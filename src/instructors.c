#include "../include/assembler.h"

const Instruction Instructors[] = {".data", ".string", ".entry", ".extern"};

const Instruction *get_instructors(void) { return Instructors; }

const int get_instructors_length(void) {
  return sizeof(Instructors) / sizeof(Instructors[0]);
}
