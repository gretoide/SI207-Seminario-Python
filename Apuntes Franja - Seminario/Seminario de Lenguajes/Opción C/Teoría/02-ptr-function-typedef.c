#include <stdio.h>

double str_to_double(char *s){
double d;
  sscanf(s,"%lf",&d);
  return d;
}
typedef double (*ptr_function)(char *);

int main() {
  char * str = "3.14159";
  ptr_function p_fun;
  p_fun = str_to_double;
  printf("%s convertido da %10.5f\n", str,p_fun(str));
  return 0;
}
