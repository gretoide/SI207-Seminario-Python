#include <stdio.h>
#include <string.h>

char * my_strcpy(char *dst, const char *src) {
  char *aux = dst;
  while ((*dst++ = *src++));
  return aux;
}

int main(int count, const char * args[]) {
  int i;
  for (i = 0; i < count; i++)
  {
    char str[1024], aux_1[1024];
    my_strcpy(aux_1, my_strcpy(str, args[i]));
    printf("Copiamos %s => %s[%s]\n", args[i], my_strcpy(str, args[i]), str);
  }
  return 0;
}
