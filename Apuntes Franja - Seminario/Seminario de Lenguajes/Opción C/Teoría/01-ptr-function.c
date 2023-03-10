#include <stdio.h>
#include <strings.h>
#include <string.h>
#define MAX_SIZE 1024

int comprobar(const char *, const char *, int (*cmp) (const char *, const char *));

int main() {
int res;
char s1[MAX_SIZE],
     s2[MAX_SIZE];
  int (*p)(const char *, const char*);
  printf("Ingrese dos cadenas separadas por espacio: ");
  scanf("%s %s",s1,s2);
  p = strcasecmp;
  printf ("La comparacion usando strcasecmp dice que %s es %s que %s\n",
    s1,
    (res = comprobar(s1,s2, p)) < 0? "menor": res > 0? "mayor": "igual",
    s2);
  p = strcmp;
  printf ("La comparacion usando strcmp dice que %s es %s que %s\n",
    s1,
    (res = comprobar(s1,s2, p)) < 0? "menor": res > 0? "mayor": "igual",
    s2);
  return 0;
}

int comprobar(const char *a, const char *b, int (*cmp) (const char *, const char *)) {
  return cmp(a,b);
}
