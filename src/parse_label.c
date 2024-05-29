#include "../include/utils.h"
#include <regex.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LABEL_REGEX "^[A-Z]+:"
#define MAX_MATCHES 100

char *parse_label(char *line, int *line_cursor) {
  regex_t regex;
  regmatch_t matches[MAX_MATCHES];

  int reti;
  reti = regcomp(&regex, LABEL_REGEX, REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    exit(EXIT_FAILURE);
  }
  reti = regexec(&regex, line, MAX_MATCHES, matches, 0);
  regfree(&regex);
  if (!reti) {
    char match[MAX_MATCHES];
    int start = matches[0].rm_so;
    int end = matches[0].rm_eo - 1;
    strncpy(match, &line[start], end - start);
    match[end - start] = '\0';
    char *result = malloc(strlen(match) + 1);
    strcpy(result, match);
    *line_cursor = end + 1;
    return result;
  }
  return NULL;
}
