#include <stdio.h>

int my_strlen_v2(char *s){
  char *q = s;
  while (*q) q++;
  return q - s;
}

int main(int count, char * args[]) {
  int i;
  for (i = 1; i < count; i++) printf("Longitud de '%s': %d\n", args[i], my_strlen_v2(args[i]));
  return 0;
}
