#include "../include/constants.h"
#include "../include/dictionary.h"
#include "../include/dynamic_string.h"
#include "../include/macro_utils.h"
#include "../include/parser.h"
#include "../include/utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void incase_line_counter(unsigned long int *LC) {
  *LC += 1;
  return;
}

void handle_recording(char **macro_recording, ParsedLine *parsed_line,
                      Dictionary *dictionary, unsigned long int LC) {
  char *dictionary_value;
  int line_length;
  int current_dictionary_value_length;
  int new_length;
  char *combine_values;
  if (is_macro_declaration_end(parsed_line->type) == 0) {
    *macro_recording = NULL;
    printf("Exit macro_recording in line %lu\n", LC);
    return;
  }

  dictionary_value = lookup(dictionary, *macro_recording);
  line_length = safe_strlen(parsed_line->line);
  current_dictionary_value_length = safe_strlen(dictionary_value);

  new_length = line_length + current_dictionary_value_length + 1;
  combine_values = (char *)malloc(new_length * sizeof(char));
  if (dictionary_value != NULL) {
    strcpy(combine_values, dictionary_value);
    strcat(combine_values, "\n");
  }
  strcat(combine_values, parsed_line->line);
  insert(dictionary, *macro_recording, combine_values);
  free(dictionary_value);
  free(combine_values);
}

void macros_handler(FILE *assembly_file) {
  ParsedLine *parsed_line;
  char *macro_recording = NULL;
  Dictionary *dictionary = create_dictionary();
  DynamicString *am_file_content = malloc(sizeof(DynamicString));
  initDynamicString(am_file_content);
  /* Line counter */
  unsigned long int LC = 0;

  char line[MAX_LINE_LENGTH];

  while (fgets(line, sizeof(line), assembly_file)) {
    incase_line_counter(&LC);

    parsed_line = parse_line(line);
    if (is_macro_declaration_start(parsed_line->type) == 0) {
      macro_recording = parsed_line->value;
      printf("Enter macro_recording in line %lu\n", LC);
      continue;
    }

    if (macro_recording != NULL) {
      handle_recording(&macro_recording, parsed_line, dictionary, LC);
      continue;
    }

    if (is_known_operator(parsed_line->type) == 0) {
      char *macr_value = lookup(dictionary, parsed_line->type);
      if (macr_value != NULL) {
        printf("Found a macr use in line %lu\n", LC);
        strcatDynamicString(am_file_content, macr_value);
        strcatDynamicString(am_file_content, "\n");
        continue;
      }
      printf("Unknown operator in line %lu\n", LC);
      exit(EXIT_FAILURE);
    }
    strcatDynamicString(am_file_content, parsed_line->line);
    strcatDynamicString(am_file_content, "\n");
  }
  puts(am_file_content->str);

  free_dictionary(dictionary);
  freeDynamicString(am_file_content);
  puts("Finished macros_handler");
}
