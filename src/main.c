#include "lib.c"
#include <stdio.h>

#define EX2

#ifdef EX2
int main() {
  float valor, reajuste;

  do {
    printf("Coloca um numero: ");
    scanf("%f", &valor);
  } while (valor <= 0);

  reajuste = valor * 1.1;
  printf("O valor reajustado é de %f\n", reajuste);
  return 0;
}
#endif /* ifdef EX2 */

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

// bool isValidInput(void *input) { return ((char *)input)[0] == 'y'; }
//
// int main() {
//   char result = ((char *)readCharWithValidation(isValidInput,
//                                                 "Enter 'y' to continue:
//                                                 "))[0];
//
//   printf("\nYou entered: %c\n", result);
//
//   return 0;
// }
#endif
