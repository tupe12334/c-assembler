#pragma once
#include <stdio.h>

FILE *fetch_file(char *full_file_name);
void write_file(char *filename, char *content);
void append_to_file(char *filename, char *content);
void reset_file(char *filename);
