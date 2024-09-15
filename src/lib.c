#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

char classify_person(float height, float weight) {
  if (height < 1.20) {
    if (weight < 60) {
      return 'A';
    } else if (weight < 90) {
      return 'D';
    } else {
      return 'G';
    }
  }

  if (height < 1.70) {
    if (weight < 60) {
      return 'B';
    } else if (weight < 90) {
      return 'E';
    } else {
      return 'H';
    }
  }

  if (weight < 60) {
    return 'C';
  } else if (weight < 90) {
    return 'F';
  } else {
    return 'I';
  }
}

typedef bool (*ValidationFunc)(char);
char readCharWithValidation(ValidationFunc validate, char *message) {
  char ch;

  while (true) {
    printf("%s", message);
    ch = getchar();

    if (validate(ch)) {
      break;
    }
  }
  return ch;
}

float readNumber(char *message, ...) {
  va_list args;
  va_start(args, message);
  float number;
  printf(message, args);
  scanf("%f", &number);
  va_end(args);

  return number;
}
