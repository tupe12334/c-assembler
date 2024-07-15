const char *OpCodes[] = {"mov", "cmp", "add", "sub", "lea", "clr",
                         "not", "inc", "dec", "jmp", "bne", "red",
                         "prn", "jsr", "rts", "stop"};
const char **get_op_codes(void) { return OpCodes; }
const int get_op_codes_length(void) {
  return sizeof(OpCodes) / sizeof(OpCodes[0]);
}
