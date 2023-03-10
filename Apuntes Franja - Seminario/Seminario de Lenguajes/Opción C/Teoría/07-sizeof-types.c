#include <stdio.h>
#include <stdlib.h>
#include <strings.h>


char * types[] = {"char", "int", "short", "long", "float", "double", "pointer"};

long int size_of_type(const char *t) {
  if (!strcasecmp(t,"char")) return sizeof(char);
  if (!strcasecmp(t,"int")) return sizeof(int);
  if (!strcasecmp(t,"short")) return sizeof(short);
  if (!strcasecmp(t,"long")) return sizeof(long);
  if (!strcasecmp(t,"float")) return sizeof(float);
  if (!strcasecmp(t,"double")) return sizeof(double);
  if (!strcasecmp(t,"pointer")) return sizeof(void *);
  printf("Se envió un tipo desconocido => %s. Se aborta\n", t);
  exit(1);
}

int main(){
  int i;

  for (i=0; i < 7; i++)  printf ("El tamaño de %s es %ld\n", types[i], size_of_type(types[i]));

  return 0;

}
