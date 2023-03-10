#include <stdio.h>
int main()
{
  int x = 1;
  x++;
  printf("\n\nEste programa debe tirar un warning si se compila con las opciones -Wall -pedantic\n\n");
  /*{ */
  int y = x;
  printf("El valor de x=%d - el de y=%d\n", x, y);
  /*} */
  return 0;
}
