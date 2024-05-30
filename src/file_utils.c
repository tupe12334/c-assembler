
#include <stdio.h>
#include <stdlib.h>

FILE *fetch_file(char *full_file_name) {
  FILE *file;
  file = fopen(full_file_name, "r");

  if (file == NULL) {
    printf("File %s does not exist\n", full_file_name);
    exit(EXIT_FAILURE);
  }

  return file;
}

FILE *write_file(char *content) {
  FILE *file;
  file = fopen("output.ob", "w");

  if (file == NULL) {
    printf("File output.ob does not exist\n");
    exit(EXIT_FAILURE);
  }

  fprintf(file, "%s", content);
  fclose(file);

  return file;
}
