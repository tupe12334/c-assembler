#include "../include/constants.h"
#include "../include/dictionary.h"
#include "../include/line.h"
#include "../include/line_handler.h"
#include "../include/parser.h"
#include "../include/program.h"
#include "../include/tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

void first_pass_handler(Program *program, FILE *post_macro_file,
                        Dictionary *label_table,
                        MetaAssembler *meta_assembler) {
  char line[MAX_LINE_LENGTH];
  TokenizedLine *tokenized_line;
  ParsedLine *parsed_line;

  puts("Starting to run the first pass on file");

  while (fgets(line, sizeof(line), post_macro_file)) {
    tokenized_line = tokenize(line);
    parsed_line = parse_line(*tokenized_line, meta_assembler);
    line_handler(program, label_table, parsed_line, meta_assembler);
  }
  free(parsed_line);
  free(tokenized_line);
  free_dictionary(label_table);
}
