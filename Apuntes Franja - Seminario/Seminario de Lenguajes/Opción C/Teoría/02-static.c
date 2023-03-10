#include <stdio.h>

int cuento() {
  static int x;
  return x++;
}

int main() {
int i;
  for(i=0 ; i<10 ; i++) printf("%d\n", cuento());
  return 0;
}

