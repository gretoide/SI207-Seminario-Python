#include <stdio.h>


int main(int argc, char *argv[]) { 
char letra,
     *arg = argv[1];
int vocMin = 0, 
    vocMay = 0,
    otros = 0;
  for (;argc > 1 && (letra=*arg); arg++) {
    switch (letra)  {
      case 'a': case 'e': case 'i': case 'o': case 'u': 
        vocMin++;
        break;
      case 'A': case 'E': case 'I': case 'O': case 'U': 
        vocMay++;
        break;
      default:
        otros++;
        break;
    }
  }
  printf("Cantidad\n"
      "\tVocales minusculas: %d\n"
      "\tVocales mayusculas: %d\n"
      "\tOtras letras: %d\n",vocMin, vocMay,otros);
  return 0;
}
