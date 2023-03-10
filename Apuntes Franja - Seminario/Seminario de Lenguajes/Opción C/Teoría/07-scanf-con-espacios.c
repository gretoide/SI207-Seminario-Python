// http://stackoverflow.com/questions/1247989/how-do-you-allow-spaces-to-be-entered-using-scanf
#include <stdio.h>
#include <stdlib.h>

int main()
{ char nombre[100];
  char * scanf_aloc = NULL;
  int ret=0;

  printf("Ingrese su nombre: ");
  ret = scanf("%99[^\n]", nombre);

  if (ret) printf("Su nombre es: %s\n", nombre);
  else printf("Error\n");
  getchar();

  printf("Antes de leer otro nombre, mostramos el puntero %p\n", scanf_aloc);
  printf("Ingrese otro string: ");
  ret = scanf("%99m[^\n]", &scanf_aloc);
  if (ret) {
    printf("Su nombre es: %s\nEl puntero ahora es: %p\n", scanf_aloc, scanf_aloc);
    free(scanf_aloc);
  } else printf("Error\n");

  return 0;
}
