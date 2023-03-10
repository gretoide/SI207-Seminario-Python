#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 80
#define WORD_LENGTH 256
#define MSG "Ingrese palabras separadas por espacio, enter, etc. Presione Ctrl+(D linux|Z windows) para salir\n"

unsigned read_words(char *words[]) 
{
  char w[WORD_LENGTH];
  unsigned c=0;
  printf(MSG);
  while(scanf("%s",w) > 0 && strlen(w) > 0 && c < MAX_WORDS) {
    words[c]= malloc((strlen(w)+1)*sizeof(char));
    strcpy(words[c], w);
    c++;
  }
  return c;
}

void sort(char *words[], unsigned count)
{
  int i,j;
  for(i=0;i<count;i++) {
    for(j=i+1;j<count; j++) {
      if (strcmp(words[i],words[j])>0) {
        char * aux = words[i];
        words[i] = words[j];
        words[j] = aux;
      }
    }
  }
}

void print(char *words[], unsigned count)
{
  int i;
  for(i=0; i<count; i++) printf("%03d: %s\n", i+1, words[i]);
}

int main(void)
{
  char *words[MAX_WORDS];
  unsigned count;
  if((count = read_words(words))>0){
    int i;
    sort(words, count);
    print(words, count);
    for (i=0; i < count; i++) free(words[i]);
  }
  else printf ("No words read\n");
  return 0;
}
