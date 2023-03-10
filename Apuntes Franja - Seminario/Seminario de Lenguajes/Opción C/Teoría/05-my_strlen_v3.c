#include <stdio.h>

int my_strlen_v3(char *s){
  int i = 0;
  while (s[i++]);
  return i - 1;
}

int main(int count, char * args[]) {
  int i;
  for (i = 1; i < count; i++) printf("Longitud de '%s': %d\n", args[i], my_strlen_v3(args[i]));
  return 0;
}
