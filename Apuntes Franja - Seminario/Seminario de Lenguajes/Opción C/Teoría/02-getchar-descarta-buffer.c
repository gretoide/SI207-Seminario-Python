#include<stdio.h>

int main(void)
{
  int c;
  printf("\nIngrese un caracter ");
  c = getchar();

  while ( c != EOF ) {
    putchar(c);

    while ((c = getchar()) != '\n' && c != EOF );
    if ( c == EOF ) return 0;
//    while ((c = getchar()) != '\n');
    printf("\nIngrese un caracter ");
    c = getchar();
  }

  printf("\nTermina el programa");
  return 0;
}
