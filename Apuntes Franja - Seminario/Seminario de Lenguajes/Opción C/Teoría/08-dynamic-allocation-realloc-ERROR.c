#include <stdlib.h>
#include <stdio.h>

#define READ_NUMBER_MESSAGE "Ingrese un numero (%d para terminar): "

int read_number(int end_num) {
  int aux;
  printf(READ_NUMBER_MESSAGE, end_num);
  while(scanf("%d", &aux) != 1) {
    fprintf(stderr, "Error! Intente nuevamente: ");
    getchar();
  }
  return aux;
}

void list_initialize(int ** list, int * size) {
  *size = 0;
  *list = NULL;
}

void list_add(int **ptr_list, int *size, int element) {
  *ptr_list = realloc(*ptr_list, sizeof(int) * ++(*size));
  *ptr_list[*size - 1] = element;
}

void list_destroy(int **list, int * size) {
  free(*list);
  *list = NULL;
  *size = 0;
}

int main() {
  int num,
      * my_list,
      my_list_size;
  list_initialize(&my_list, &my_list_size);
  while ((num = read_number(999))!= 999) list_add(&my_list, &my_list_size, num);
  printf("Contenido de la lista\n");
  for(num = 0; num < my_list_size; num++) printf("my_list[%d] => %d\n", num, my_list[num]);
  list_destroy(&my_list, &my_list_size);
  return 0;
}
