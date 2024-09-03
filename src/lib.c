#include <stdbool.h>
#include <stdio.h>

void wait_for_keypress_char(int (*validate)(void *), void *data) {
  scanf("%c", (char *)data);

  while (!validate(data)) {
    scanf("%c", (char *)data);
  }
}

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
