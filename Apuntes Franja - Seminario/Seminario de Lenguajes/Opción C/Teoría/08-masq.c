#include <stdio.h>

int main ()
{


  unsigned char x = 128;

  while ((x & 16) == 0)
  {

    printf("El valor de x es %d\n", x);

    x >>= 1;

  }

  printf ("El complemento a 1 de %d es %d (sin signo)\n",x, (unsigned char) ~x);
  printf ("El complemento a 1 de %d es %d\n",x, ~x);

  return 0;

}
