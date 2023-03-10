#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_WORD 1024


int compare_strings(const void *p1, const void *p2){
  return strcasecmp(* (char **) p1, * (char **) p2);
}

int main() {
unsigned count = 0, i;
char word[MAX_WORD];
char ** words = NULL;
  printf("Ingrese palabras separadas por espacio (EOF para terminar): ");
  while (scanf("%s", word) > 0)
  {
    words = realloc(words, sizeof(char *)*++count);
    words[count - 1] = strdup(word);
  }
  qsort(words, count, sizeof(char *), &compare_strings);
  for (i=0; i < count; i++) {
      printf("%03d: %s\n", i+1, words[i]);
      free(words[i]);
  }
  free(words);
  return 0;
}
