/* feof example: byte counter 
http://www.cplusplus.com/reference/cstdio/feof/
*/
#include <stdio.h>

int main (int argc, const char *argv[])
{
  FILE * pFile;
  int n = 0;
  pFile = fopen (argv[1],"rb");
  if (pFile==NULL) perror ("Error abriendo el archivo");
  else
  {
    while (fgetc(pFile) != EOF) {
      ++n;
    }
    if (feof(pFile)) {
      puts ("Alcanzado el End-of-File.");
      printf ("Numero total de bytes leidos: %d\n", n);
    }
    else puts ("End-of-File No alcanzado.");
    fclose (pFile);
  }
  return 0;
}
