#include <limits.h>
#include <stdio.h>

int * two_mins(int vec[], int dim) {
  int ret[2];
  int i;
  for (i=0; i < 2; ret[i++] = INT_MAX);
  for (i=0; i < dim; i++) {
    if (vec[i] < ret[0]) {
      ret[1] = ret[0];
      ret[0] = vec[i];
    }else{
      if (vec[i] < ret[1]) {
        ret[1] = vec[i];
      }
    }
  }
  return ret;
}

int main() {
  int test[] = {100, -10, 20, 5, 2},
      test2[] = {-100, -10, -20, 5, 2},
      * mins = two_mins(test, 5),
      * mins2 = two_mins(test2, 5);
    printf("Los minimos del arreglo test son %d y %d\n", mins[0], mins[1]);
    printf("Los minimos del arreglo test2 son %d y %d\n", mins2[0], mins2[1]);
  return 0;
}
