#include <stdio.h>

int main(void)
{

  int a = 58;
  float f=12352.52345;
  char s[] = "Hola Mundo";

  printf("Imprime los valores: |%d| |%c| |%#x| |%#08X| |%-4d| |%4.3d|\n", a,a,a,a,a,a);

  printf("Imprime los valores: |%#0.2f| |%0.2f| |%-+30.3f|\n", (double) a, f, f);

  printf("Imprime los valores: |%-20s| |%20.3s|\n", s,s);

  return 0;
}
