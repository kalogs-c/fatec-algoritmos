#include <stdarg.h>
#include <stdio.h>

#define ATV1

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
  float numeros[4] = {0, 0, 0, 0};

  do {
    while (numeros[0] <= 10 || numeros[0] >= 25) {
      numeros[0] = readNumber("Digite um valor entre 10 e 25: ");
    }

    while (numeros[1] <= 0) {
      numeros[1] = readNumber("Digite um valor maior que 0: ");
    };

    numeros[2] = numeros[0] + numeros[1];
    numeros[3] = numeros[0] * numeros[1] * numeros[2];

    for (int i = 0; i < 4; i++) {
      result += pow(numeros[i], 2);
    }

    if (result < 50000) {
      puts("O resultado e menor que 50000");
      for (int i = 0; i < 4; i++) {
        numeros[i] = 0;
      }
    }
  } while (result < 50000);

  printf("O resultado e %f\n", result);

  return 0;
}
#endif /* ifdef ATV1 */

#ifdef ATV2
char getConceito(float media_aproveitamento) {
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
  int id;
  do {
    id = readNumber("Digite o numero de identificacao: ");
  } while (id < 0);

  float notas[3];
  for (int i = 0; i < 3; i++) {
    do {
      notas[i] = readNumber("Digite a %d nota: ", i + 1);
    } while (notas[i] < 0 || notas[i] > 10);
  }

  float media_dos_ex;
  do {
    media_dos_ex = readNumber("Digite a media dos exercicios: ");
  } while (media_dos_ex < 0 || media_dos_ex > 10);

  float media_aproveitamento =
      (notas[0] + notas[1] * 2 + notas[2] * 3 + media_dos_ex) / 7;

  char conceito = getConceito(media_aproveitamento);
  char *status =
      (conceito == 'D' || conceito == 'E') ? "REPROVADO" : "APROVADO";

  puts("------------------------------");
  printf("O aluno de ID %d esta %s\nConceito: %c\n", id, status, conceito);

  puts("Notas ----------");
  for (int i = 0; i < 3; i++) {
    printf("| Nota %i - %.1f |\n", i + 1, notas[i]);
  }
  puts("----------------");

  printf("A media dos exercicios foi %.1f\n", media_dos_ex);
  printf("A media do aproveitamento foi %.1f\n", media_aproveitamento);

  printf("%s\n", status);
  puts("------------------------------");

  return 0;
}
#endif /* ifdef ATV2 */

#ifdef ATV3
int main() {
  float nums[3];

  do {
    for (int i = 0; i < 3; i++) {
      nums[i] = readNumber("Digite o %d numero: ", i + 1);
    }

    if (nums[0] == nums[1] && nums[1] == nums[2]) {
      puts("Todos os numeros sao iguais. Tente novamente.");
    }
  } while (nums[0] == nums[1] && nums[1] == nums[2]);

  float max = nums[0];
  for (int i = 1; i < 3; i++) {
    if (nums[i] > max) {
      max = nums[i];
    }
  }

  printf("O maior valor e %g\n", max);
  return 0;
}
#endif /* ifdef ATV3 */

#ifdef ATV4
#include <stdbool.h>
#include <string.h>

bool verificarTriangulo(int lados[3]) {
  return lados[0] + lados[1] > lados[2] && lados[1] + lados[2] > lados[0] &&
         lados[0] + lados[2] > lados[1];
}

int main() {
  int lados[3];
  do {
    for (int i = 0; i < 3; i++) {
      do {
        lados[i] = readNumber("Digite o %d lado: ", i + 1);
      } while (lados[i] <= 0);
    }

    if (!verificarTriangulo(lados)) {
      puts("Os lados informados nao formam um triangulo. Tente novamente.");
    }
  } while (!verificarTriangulo(lados));

  char tipo[11] = "escaleno";

  if (lados[0] == lados[1] && lados[1] == lados[2]) {
    strcpy(tipo, "equilatero");
  } else if (lados[0] == lados[1] || lados[1] == lados[2] ||
             lados[0] == lados[2]) {
    strcpy(tipo, "isosceles");
  }

  printf("O triangulo e %s\n", tipo);

  return 0;
}
#endif /* ifdef ATV4 */
