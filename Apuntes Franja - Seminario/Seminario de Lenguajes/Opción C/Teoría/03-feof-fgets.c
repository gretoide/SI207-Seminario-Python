#include <stdio.h> 
#include <stdlib.h> 


int main(int argc, const char * argv[])
{
  FILE *fp;
  char buf[BUFSIZ] = "BASURA";
  int i;
  if (argc != 2) 
  {
    printf("Debe indicar un archivo a leer como parámetro\n");
    return 1;
  }
  if ((fp = fopen(argv[1], "r")) == NULL)
  {
    perror (argv[1]);
    return (EXIT_FAILURE);
  }
  i = 0;
  while (fgets(buf, sizeof(buf), fp) != NULL)
  {
    printf ("Linea %4d: %s", i, buf);
    i++;
  }
  fclose(fp);
  return(0);
}
