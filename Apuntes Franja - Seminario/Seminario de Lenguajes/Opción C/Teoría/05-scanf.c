#include <stdio.h>

int main(void){
  //Clase 2. Entrada/Salida  
  int x,y, res;
  printf("\nIngrese dos valores enteros separados por -, luego presione enter:");
  res=scanf("%d-%d",&x,&y);
  printf("\nSe leyeron: \n\t1\t=>\t%d\n\t2\t=>\t%d\nEl resultado del scanf fue: %d\n", x, y, res);
  return 0;
}
