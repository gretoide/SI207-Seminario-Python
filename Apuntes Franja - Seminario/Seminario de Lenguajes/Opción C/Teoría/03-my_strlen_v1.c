#include <stdio.h>

int my_strlen_v1(char s[]){
  int i = 0;
  while ( s[i] ) i++;
  return i;
}

int main(int count, char * args[]) {
  int i;
  for (i = 1; i < count; i++) printf("Longitud de '%s': %d\n", args[i], my_strlen_v1(args[i]));
  return 0;
}
