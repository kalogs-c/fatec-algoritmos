#include "lib.c"
#include <stdio.h>

#define EX25

#ifdef EX25
int main() {
  float weight;
  float height;

  printf("weight: ");
  scanf("%f", &weight);

  printf("height: ");
  scanf("%f", &height);

  printf("%c\n", classify_person(height, weight));

  return 0;
}
#endif
