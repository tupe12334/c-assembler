const char *OpCodes[] = {"mov", "cmp", "add", "sub", "lea", "clr",
                         "not", "inc", "dec", "jmp", "bne", "red",
                         "prn", "jsr", "rts", "stop"};
const char **get_op_codes() { return OpCodes; }
const int get_op_codes_length() { return sizeof(OpCodes) / sizeof(OpCodes[0]); }