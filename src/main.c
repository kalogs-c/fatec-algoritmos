#include "lib.c"
#include <stdio.h>

#define EX10

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

#ifdef EX4
float get_desconto_inss(float salario) {
  if (salario <= 1100) {
    return 0.0;
  } else if (salario <= 2203.48) {
    return 0.075;
  } else if (salario <= 3305.22) {
    return 0.09;
  } else if (salario <= 6433.57) {
    return 0.12;
  } else {
    return 0.14;
  }
}

int main() {
  float hora_aula = readNumber("Digite o valor da hora de aula: ");
  float numero_de_aulas = readNumber("Digite o valor das aulas: ");

  float salario_bruto = hora_aula * numero_de_aulas;

  float desconto_inss = get_desconto_inss(salario_bruto);

  float salario_liquido = salario_bruto - (salario_bruto * desconto_inss);

  printf("Salario liquido: %.2f\n", salario_liquido);
  return 0;
}
#endif /* ifdef EX4 */

#ifdef EX10
int main() {
  float produto, inflacao;

  do {
    produto = readNumber("Digite o preco do produto\n");
  } while (produto <= 0);

  inflacao = produto < 100 ? produto * 1.10 : produto * 1.20;
  printf("O valor inflacionado e de: %g", inflacao);
}
#endif /* ifndef  */

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
