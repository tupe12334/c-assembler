#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_binary(unsigned int num) {
  if (num == 0) {
    printf("0");
    return;
  }

  int msb = sizeof(num) * 8 - 1;
  while (!(num & (1 << msb)) && msb > 0) {
    msb--;
  }

  for (int i = msb; i >= 0; i--) {
    printf("%d", (num & (1 << i)) ? 1 : 0);
  }
}

char *binary_to_octal(const char *binary) {
  int decimal = 0;
  int len = strlen(binary);

  for (int i = 0; i < len; i++) {
    if (binary[i] == '1') {
      decimal += pow(2, len - 1 - i);
    }
  }

  int octal_len = (int)ceil(log(decimal + 1) / log(8)) + 1;
  char *octal = (char *)malloc(octal_len * sizeof(char));

  int index = octal_len - 2;
  while (decimal > 0) {
    octal[index--] = (decimal % 8) + '0';
    decimal /= 8;
  }
  octal[octal_len - 1] = '\0';

  while (octal[0] == '\0' && octal[1] != '\0') {
    memmove(octal, octal + 1, octal_len - 1);
    octal_len--;
  }

  return octal;
}
char *decimal_to_binary(int8_t decimal) {
  char *binary = malloc(16 * sizeof(char));
  uint16_t unsigned_val;

  if (decimal < 0) {
    unsigned_val = (uint16_t)((int16_t)decimal & 0x7FFF);
  } else {
    unsigned_val = (uint16_t)decimal;
  }

  for (int i = 14; i >= 0; i--) {
    binary[i] = (unsigned_val & 1) ? '1' : '0';
    unsigned_val >>= 1;
  }
  binary[15] = '\0';

  return binary;
}
char *decimal_to_octal(int decimal) {
  static char octal[100];
  int i = 0;

  if (decimal == 0) {
    octal[i++] = '0';
  } else {
    while (decimal != 0) {
      octal[i++] = (decimal % 8) + '0';
      decimal /= 8;
    }
  }

  octal[i] = '\0';

  for (int j = 0; j < i / 2; j++) {
    char temp = octal[j];
    octal[j] = octal[i - 1 - j];
    octal[i - 1 - j] = temp;
  }

  return octal;
}
