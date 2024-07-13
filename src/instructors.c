#include "../include/assembler.h"

const Instruction *Instructors[] = {".data", ".string", ".entry", ".extern"};

const Instruction **get_instructors() { return Instructors; }

const int get_instructors_length() {
  return sizeof(Instructors) / sizeof(Instructors[0]);
}
