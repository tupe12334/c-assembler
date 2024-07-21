#include "../include/constants.h"
#include "../include/dictionary.h"
#include "../include/line.h"
#include "../include/line_handler.h"
#include "../include/parser.h"
#include "../include/program.h"
#include "../include/tokenizer.h"
#include <stdio.h>
#include <stdlib.h>

void pass_handler(Program *program, FILE *file, Dictionary *label_table,
                  MetaAssembler *meta_assembler) {
  char line[MAX_LINE_LENGTH];
  TokenizedLine *tokenized_line;
  ParsedLine *parsed_line;
  printf("Starting the %s pass\n",
         meta_assembler->pase == FIRST_RUN ? "first" : "second");

  rewind(file);
  puts("Rewinded the file");
  while (fgets(line, sizeof(line), file)) {
    tokenized_line = tokenize(line);
    parsed_line = parse_line(*tokenized_line, meta_assembler);
    line_handler(program, label_table, parsed_line, meta_assembler);
  }
  free(tokenized_line);
  free(parsed_line);
}
