#include <stdio.h>
#include <stdarg.h>

int sum(int count, ...)
{
  va_list ap;
  int i;
  int partial = 0;
  va_start(ap, count);
  for(i=0; i<count; i++) partial += va_arg(ap, int);
  va_end(ap);
  return partial;
}

int main() {
  printf("El resultado de %d + %d + %d + %d = %d\n", 1,2,3,4,sum(4,1,2,3,4));
  printf("El resultado de %d + %d  = %d\n", 1,2,sum(2,1,2));
  return 0;
}
