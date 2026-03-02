#include "utils.h"

void reverseStr(char str[], int length) {
  int start = 0;
  int end = length - 1;
  while (start < end) {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    end--;
    start++;
  }
}

char *itoa(int num, char *buffer, int base) {
  int i = 0;
  int isNegative = 0;

  if (num == 0) {
    buffer[i++] = '0';
    buffer[i] = '\0';
    return buffer;
  }

  if (num < 0 && base == 10) {
    isNegative = 1;
    num = -num;
  }

  while (num != 0) {
    int rem = num % base;
    buffer[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
    num = num / base;
  }

  if (isNegative)
    buffer[i++] = '-';

  reverseStr(buffer, i);

  return buffer;
}

int atoi(char *buffer) {
  int result = 0;
  int sign = 0;
  int i = 0;

  if (buffer[0] == '-') {
    sign = -1;
    i++;
  } else if (buffer[0] == '+') {
    i++;
  }

  while (buffer[i] != '\0') {
    if (buffer[i] < '0' || buffer[i] > '9') {
      break;
    }
    result = result * 10 + (buffer[i] - '0');
    i++;
  }

  return sign * result;
}
