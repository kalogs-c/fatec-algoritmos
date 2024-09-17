#include <stdarg.h>
#include <stdio.h>

#define ATV4

float readNumber(char *message, ...) {
  va_list args;
  va_start(args, message);
  float number;
  vfprintf(stderr, message, args);
  scanf("%f", &number);
  va_end(args);

  return number;
}

#ifdef ATV1
#include <math.h>

int main() {
  float result = 0;
  float numeros[4];

  do {
    do {
      numeros[0] = readNumber("Digite um valor entre 10 e 25: ");
    } while (numeros[0] <= 10 || numeros[0] >= 25);

    do {
      numeros[1] = readNumber("Digite um valor maior que 0: ");
    } while (numeros[1] <= 0);

    numeros[2] = numeros[0] + numeros[1];
    numeros[3] = numeros[0] * numeros[1] * numeros[2];

    for (int i = 0; i < 4; i++) {
      result += pow(numeros[i], 2);
    }

    if (result < 50000) {
      printf("O resultado é menor que 50000");
    }
  } while (result < 50000);

  printf("O resultado é %f\n", result);

  return 0;
}
#endif /* ifdef ATV1 */

#ifdef ATV2
char get_conceito(float media_aproveitamento) {
  if (media_aproveitamento >= 9.0) {
    return 'A';
  } else if (media_aproveitamento >= 7.5) {
    return 'B';
  } else if (media_aproveitamento >= 6.0) {
    return 'C';
  } else if (media_aproveitamento >= 4.0) {
    return 'D';
  } else {
    return 'E';
  }
}

int main() {
  int id = readNumber("Digite o numero de identificação: ");
  float notas[3];

  for (int i = 0; i < 3; i++) {
    do {
      notas[i] = readNumber("Digite a %dº nota: ", i + 1);
    } while (notas[i] < 0 || notas[i] > 10);
  }

  float media_dos_ex = readNumber("Digite a media dos exercícios: ");

  float media_aproveitamento =
      (notas[0] + notas[1] * 2 + notas[2] * 3 + media_dos_ex) / 7;

  char conceito = get_conceito(media_aproveitamento);
  char *status = conceito == 'D' || conceito == 'E' ? "REPROVADO" : "APROVADO";

  printf("O aluno de ID %d esta %s com média %.1f e conceito %c\n", id, status,
         media_aproveitamento, conceito);

  printf("%s\n", status);

  return 0;
}
#endif /* ifdef ATV2 */

#ifdef ATV3
int main() {
  float nums[3];

  do {
    for (int i = 0; i < 3; i++) {
      nums[i] = readNumber("Digite o %dº número: ", i + 1);
    }

    if (nums[0] == nums[1] && nums[1] == nums[2]) {
      printf("Todos os números sao iguais. Tente novamente.\n");
    }
  } while (nums[0] == nums[1] && nums[1] == nums[2]);

  float max = nums[0];
  for (int i = 1; i < 3; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }

  printf("O maior valor é %f", max);
  return 0;
}
#endif /* ifdef ATV3 */

#ifdef ATV4
#include <stdbool.h>

bool verificar_triangulo(int lados[3]) {
  return lados[0] + lados[1] > lados[2] && lados[1] + lados[2] > lados[0] &&
         lados[0] + lados[2] > lados[1];
}

int main() {
  int lados[3];
  do {
    for (int i = 0; i < 3; i++) {
      do {
        lados[i] = readNumber("Digite o %dº lado: ", i + 1);
      } while (lados[i] <= 0);
    }

    if (!verificar_triangulo(lados)) {
      printf("Os lados informados não formam um triangulo. Tente novamente.\n");
    }
  } while (!verificar_triangulo(lados));

  char *tipo = "escaleno";

  if (lados[0] == lados[1] && lados[1] == lados[2]) {
    tipo = "equilatero";
  } else if (lados[0] == lados[1] || lados[1] == lados[2] ||
             lados[0] == lados[2]) {
    tipo = "isosceles";
  }

  printf("O triangulo é %s\n", tipo);

  return 0;
}
#endif /* ifdef ATV4 */
