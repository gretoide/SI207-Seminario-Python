#include <stdio.h>

int main()
{int val;

  do {
    printf("\nIngrese un numero entero (-1 termina, letras se descartan): ");
    while (scanf("%d", &val) != 1) 
    {
      fprintf(stderr, "Error leyendo un entero. Intente nuevamente: ");
      getchar();
    }
    printf("Se leyo: %d", val);
  } while(val != -1);
  return 0;
}

