#include <stdio.h>

float sum(float a, float b) { return a+b; }
float minus(float a, float b) { return a-b; }
float times(float a, float b) { return a*b; }
float divide(float a, float b) { return a/b; }

typedef float (*float_operation_t) (float, float);

float_operation_t operations[] = { sum, minus, times, divide, NULL};
char *names [] = { "SUMAR", "RESTAR", "MULTIPLICAR", "DIVIDIR", NULL };

int main() {
  float y=10.1, z=2.3;
  unsigned i;
  for (i=0; operations[i]; i++) printf("El resultado de %s %f con %f es %f\n", 
      names[i], y, z, operations[i](y,z));
  return 0;
}
