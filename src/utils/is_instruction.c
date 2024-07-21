#include "../../include/bool.h"
#include "../../include/constants.h"
#include "../../include/instructors.h"
#include <string.h>

unsigned short int is_instruction(string command) {
  int i;
  for (i = 0; i < get_instructors_length(); i++) {
    if (strcmp(command, get_instructors()[i]) == 0) {
      return true;
    }
  }
  return false;
}
