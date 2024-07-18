#include "../../include/string.h"
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATCHES 100

string extract_word(string line, string regex_pattern) {
  regex_t regex;
  regmatch_t matches[MAX_MATCHES];
  int reti;
  string result;
  reti = regcomp(&regex, regex_pattern, REG_EXTENDED);
  if (reti) {
    fprintf(stderr, "Could not compile regex\n");
    exit(EXIT_FAILURE);
  }
  reti = regexec(&regex, line, MAX_MATCHES, matches, 0);
  regfree(&regex);
  if (!reti) {
    char match[MAX_MATCHES];
    int start = matches[0].rm_so;
    int end = matches[0].rm_eo;
    strncpy(match, &line[start], end - start);
    match[end - start] = '\0';
    result = malloc(strlen(match) + 1);
    strcpy(result, match);
    return result;
  }
  return NULL;
}
