#include <stdio.h>
#include <string.h>
#include <limits.h>

void all_in_one(int arr[], int size, int * sum, int * min, int * max, double * avg) {
  int i;
  *sum = 0;
  *min = INT_MAX;
  *max = INT_MIN;
  for(i  = 0; i < size; i++) {
    *sum += arr[i];
    if (*min > arr[i]) *min = arr[i];
    if (*max < arr[i]) *max = arr[i];
  }
  *avg = (double) *sum / size;
}

void print_results(int arr[], int size, int sum, int min, int max, double avg) {
  int i;
  char arr_str[1024] = "[ ", aux[512];

  for(i=0; i < size - 1; i++)
  {
    sprintf(aux, "%d, ", arr[i]);
    strcat(arr_str, aux);
  }
  if (i < size) {
    sprintf(aux, "%d", arr[i]);
    strcat(arr_str, aux);
  }
  strcat(arr_str, "]");

  printf ("Datos para %s \n", arr_str);
  printf("%10s => %10d\n", "Sum", sum);
  printf("%10s => %10d\n", "Min", min);
  printf("%10s => %10d\n", "Max", max);
  printf("%10s => %13.2f\n", "Avg", avg);
}

int main() {
  int test[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int sum, min, max;
  double avg;

  all_in_one(test, 10, &sum, &min, &max, &avg);

  print_results(test, 10, sum, min, max, avg);

  return 0;
}
