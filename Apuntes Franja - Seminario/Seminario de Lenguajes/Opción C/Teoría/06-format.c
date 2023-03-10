#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void myclose(FILE *in, FILE *out) {
  if ( in != stdin) fclose(in);
  if ( out != stdout) fclose(out);
}

void help(const char * name) {
  printf (
      "Lee lineas de numeros flotantes separados por coma de un archivo\n"
      "y agrega una nueva columna con el resultado de sumar los numeros\n"
      "de la fila.\n"
      "\n\tUso: %s [-i <INPUT_FILE>] [-o <OUTPUT_FILE>]\n", name);
}

void parse(FILE *in , FILE *out) {
  int count;
  float f1,f2,f3;
  while ((count = fscanf(in,"%f,%f,%f", &f1, &f2, &f3)) ==3)
  {
    fprintf(out, "%.2f,%.2f,%.2f,%.2f\n", f1, f2, f3, f1+f2+f3);
  }
  if (!feof(in))
  {
    printf("Linea mal formada o error inesperado!!Se leyeron %d elems\n", count);
    myclose(in,out);
    exit(EXIT_FAILURE);
  }
}


int main(int count, char * args[]) {
int o;
FILE *in = stdin,
     *out = stdout;
  while ((o = getopt (count, args, "hi:o:"))!=-1) {
    switch (o) {
      case 'i':
        in = fopen(optarg, "rb");
        if (!in) {
          myclose(in, out);
          printf("Error abriendo %s", optarg);
          exit(EXIT_FAILURE);
        }
        break;
      case 'o':
        out = fopen(optarg, "wb");
        if (!out)
        {
          myclose(in, out);
          printf("Error abriendo %s", optarg);
          exit(EXIT_FAILURE);
        }
        break;
      case 'h':
      default:
        help(args[0]);
        myclose(in, out);
        exit(EXIT_FAILURE);
        break;
    }
  }
  parse(in, out);
  myclose(in, out);
  exit(EXIT_SUCCESS);
}
