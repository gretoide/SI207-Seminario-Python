#include <stdio.h>

int main() {
  int my_array[] = {10, 20};

  printf("El sizeof de un entero es: %ld\n", sizeof(int));
  printf("El sizeof de my_array es: %ld\n", sizeof(my_array));
  printf("La posicion de my_array es: %p\n", my_array);
  printf("La posicion de my_array[0] es: %p\n", &my_array[0]);
  printf("La posicion de my_array[1] es: %p\n", &my_array[1]);
  return 0;

}
