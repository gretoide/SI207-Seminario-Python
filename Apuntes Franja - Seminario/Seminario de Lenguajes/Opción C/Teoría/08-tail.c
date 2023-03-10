#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define COUNT_DEFAULT 256
#define BUFFER_SIZE 512

int main(int c, char *args[]) {
int o;
long count =  COUNT_DEFAULT;
FILE *in = NULL,
     *out= stdout;
   while ((o = getopt (c, args, "hn:i:"))!=-1) {
      switch (o) {
        case 'i':
          in = fopen(optarg, "rb");
          if (!in) {
            printf("Error abriendo %s", optarg);
            exit(EXIT_FAILURE);
          }
          break;
        case 'n':
          count = strtol(optarg, NULL, 10);
          if (count <= 0) {
            printf("La cantidad de bytes debe ser un valor mayor que cero. Ud ingreso: %s\n", optarg);
            exit(EXIT_FAILURE);
          }
          break;
        case 'h':
        default:
          printf (
              "Uso: %s -i <INPUT_FILE>  [-n <NUM>].\n"
              "\n"
              "\t-i Archivo de entrada\n"
              "\t-n Cantidad de bytes a mostrar (los últimos bytes). Se asume %d\n", args[0], COUNT_DEFAULT);
          exit(EXIT_FAILURE);
          break;
      }
   }
   if (!in) {
     printf("No especifico el archivo del cual leer\n");
     exit(EXIT_FAILURE);
   }
   if (fseek(in, 0 , SEEK_END) < 0) {
     perror(NULL);
     exit(EXIT_FAILURE);
   }
   else
   {
   long total;
   char buffer[BUFFER_SIZE];
     if ((total = ftell(in)) < count)
     {
        fprintf(stderr, "ADVERTENCIA: ha solicitado ver los ultimos %ld bytes y el total de bytes "
            "\n en el archivo es %ld. Se muestran %ld bytes\n", count, total, total);
        count = total;
     }
     if ( fseek(in, 0L - count, SEEK_END) < 0) {
       perror(NULL);
       exit(EXIT_FAILURE);
     }
     printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
     while ((count = fread(buffer, sizeof(char), BUFFER_SIZE, in)) > 0) {
       fwrite(buffer, sizeof(char), count, out);
     }
     fflush(out);
     printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
     fclose(in);
     if (out != stdout) fclose(out);
   }
   exit(EXIT_SUCCESS);
}
