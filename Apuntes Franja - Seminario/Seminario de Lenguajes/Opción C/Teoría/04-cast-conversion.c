#include <stdio.h>
int main()
{
  unsigned short i = 0x0804L;
  unsigned char c = i;

  printf("El valor del short 0x%X\n",i);
  printf("El valor del char 0x%X\n",c);
  return 0;
}
