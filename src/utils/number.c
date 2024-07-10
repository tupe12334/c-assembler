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

  // Reverse the string
  for (int j = 0; j < i / 2; j++) {
    char temp = octal[j];
    octal[j] = octal[i - 1 - j];
    octal[i - 1 - j] = temp;
  }

  return octal;
}