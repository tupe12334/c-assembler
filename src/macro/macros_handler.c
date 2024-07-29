#include "../../include/bool.h"
#include "../../include/constants.h"
#include "../../include/dictionary.h"
#include "../../include/file_utils.h"
#include "../../include/is_known_operator.h"
#include "../../include/macro_utils.h"
#include "../../include/string.h"
#include "../../include/tokenizer.h"
#include "../../include/types.h"
#include "../../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void handle_recording(string *macro_recording, TokenizedLine *tokenized_line,
                      Dictionary *dictionary, unsigned long int LC) {
  string dictionary_value;
  int line_length;
  int current_dictionary_value_length;
  int new_length;
  string combine_values;
  if (is_macro_declaration_end(tokenized_line->type) == 0) {
    *macro_recording = NULL;
    printf("Exit macro_recording in line %lu\n", LC);
    return;
  }

  dictionary_value = lookup(dictionary, *macro_recording);
  line_length = safe_strlen(tokenized_line->line);
  current_dictionary_value_length = safe_strlen(dictionary_value);

  new_length = line_length + current_dictionary_value_length + 1;
  combine_values = (string)malloc(new_length * sizeof(char));
  if (dictionary_value != NULL) {
    strcpy(combine_values, dictionary_value);
    strcat(combine_values, "\n");
  }
  strcat(combine_values, tokenized_line->line);
  update(dictionary, *macro_recording, combine_values);
  free(dictionary_value);
  free(combine_values);
}

void macros_handler(FILE *assembly_file, string filename) {
  counter LC;
  char line[MAX_LINE_LENGTH];
  TokenizedLine *tokenize_line;
  string am_filename;
  string macro_recording = NULL;
  Dictionary *dictionary = create_dictionary();

  /* Line counter */
  LC = 0;

  am_filename = str_append(filename, ".am");
  reset_file(am_filename);

  while (fgets(line, sizeof(line), assembly_file)) {
    LC++;

    if (is_comment(line) || is_line_empty(line)) {
      continue;
    };

    tokenize_line = tokenize(line);
    if (is_macro_declaration_start(tokenize_line->type) == 0) {
      macro_recording = tokenize_line->value;
      printf("Enter macro_recording in line %lu\n", LC);
      continue;
    }

    if (macro_recording != NULL) {
      handle_recording(&macro_recording, tokenize_line, dictionary, LC);
      continue;
    }
    if (is_known_operator(tokenize_line->type) == false) {
      string macr_value = lookup(dictionary, tokenize_line->type);
      if (macr_value != NULL) {
        printf("Found a macr use in line %lu\n", LC);
        append_to_file(am_filename, macr_value);
        continue;
      }
      printf("Unknown operator in line %lu, line content: %s\n", LC, line);
      exit(EXIT_FAILURE);
    }
    append_to_file(am_filename, tokenize_line->line);
  }

  free_dictionary(dictionary);
  dictionary = NULL;
  free(tokenize_line);
  free(am_filename);
  free(macro_recording);
  puts("Finished macros_handler");
  puts(COMMENT_LINE_BREAK);
}
