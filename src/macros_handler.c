#include "../include/constants.h"
#include "../include/dictionary.h"
#include "../include/macro_utils.h"
#include "../include/parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void handle_recording(char **macro_recording, ParsedLine *parsed_line,
                      Dictionary *dictionary, unsigned long int LC) {
  if (is_macro_declaration_end(parsed_line->type) == 0) {
    *macro_recording = NULL;
    printf("Exit macro_recording in line %lu\n", LC);
    return;
  }
  insert(dictionary, *macro_recording, parsed_line, 1);
}

void macros_handler(FILE *assembly_file) {
  ParsedLine *parsed_line;
  char *macro_recording = NULL;
  Dictionary *dictionary = create_dictionary();

  /* Line counter */
  unsigned long int LC = 0;

  char line[MAX_LINE_LENGTH];

  while (fgets(line, sizeof(line), assembly_file)) {
    LC++;
    parsed_line = parse_line(line);

    if (is_macro_declaration_start(parsed_line->type) == 0) {
      macro_recording = parsed_line->value;
      printf("Enter macro_recording in line %lu\n", LC);
      continue;
    }

    if (macro_recording != NULL) {
      puts(macro_recording);
      handle_recording(&macro_recording, parsed_line, dictionary, LC);
      continue;
    }
    puts(line);
  }
  puts("Finished macros_handler");
}