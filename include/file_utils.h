#pragma once
#include "string.h"
#include <stdio.h>

FILE *fetch_file(string full_file_name);
void write_file(string filename, string content);
void append_to_file(string filename, string content);
void reset_file(string filename);
