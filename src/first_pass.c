#include "../include/constants.h"
#include "../include/dictionary.h"
#include "../include/line.h"
#include "../include/line_handler.h"
#include "../include/parser.h"
#include "../include/tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

void first_pass_handler(DynamicArray *program, FILE *post_macro_file,
                        MetaAssembler meta_assembler) {
  char line[MAX_LINE_LENGTH];
  TokenizedLine *tokenized_line;
  ParsedLine *parsed_line;
  Dictionary *label_table;
  puts("Starting to run the first pass on file");
  label_table = create_dictionary();

  while (fgets(line, sizeof(line), post_macro_file)) {
    tokenized_line = tokenize(line, meta_assembler);
    parsed_line = parse_line(*tokenized_line, meta_assembler);
    line_handler(program, parsed_line);
    if (parsed_line->tokens.label != NULL) {
      insert(label_table, parsed_line->tokens.label, "");
    }
  }
  free(parsed_line);
  free(tokenized_line);
  free_dictionary(label_table);
}
