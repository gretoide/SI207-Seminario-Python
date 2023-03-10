#include<stdio.h>

int main() 
{

  int c;

  printf("\nIngrese un caracter ");
  c=getchar();

  while (c!=EOF) 
  {
    putchar(c);
    printf("\nIngrese un caracter ");
    c=getchar();
  }

  printf("\nTermine el programa");

  return 0;
}
