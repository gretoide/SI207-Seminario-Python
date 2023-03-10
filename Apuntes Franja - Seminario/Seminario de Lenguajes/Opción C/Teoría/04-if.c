#include <stdio.h>

void debug(const char *msg) {
#if DEBUG
  fprintf(stderr, "%s\n", msg);
#endif
}

int main() {
  int x;
  debug("Inicializo x en 0");
  x = 0;
  printf("El valor de x es %d\n", x);
  debug("Salgo del programa en forma anormal: retorno 2");
  return 2;
}
