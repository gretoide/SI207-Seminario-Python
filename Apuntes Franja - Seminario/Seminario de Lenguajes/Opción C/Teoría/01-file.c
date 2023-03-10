#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <locale.h> /* Agrega soporte de traducciones */
extern int errno;

int main(int argc, char *argv[]) {
  FILE *fp;
  setlocale(LC_ALL, ""); /* Permite mensajes en castellano */
  if (argc==2) {
    if ((fp = fopen(argv[1], "r"))){
      printf("El arch. %s pudo abrirse\n", argv[1]);
      fclose(fp);
    }
    else printf("ERROR al abrir %s:=> %s\n", argv[1], strerror(errno)); /* Manejo de errores */
  }
  else printf("Debe enviar nombre de archivo como parametro\n");
  return 0;
}
