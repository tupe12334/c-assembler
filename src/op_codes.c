#include "../include/string.h"

const string OpCodes[] = {"mov", "cmp", "add", "sub", "lea", "clr",
                          "not", "inc", "dec", "jmp", "bne", "red",
                          "prn", "jsr", "rts", "stop"};
const string *get_op_codes(void) { return OpCodes; }
const int get_op_codes_length(void) {
  return sizeof(OpCodes) / sizeof(OpCodes[0]);
}
