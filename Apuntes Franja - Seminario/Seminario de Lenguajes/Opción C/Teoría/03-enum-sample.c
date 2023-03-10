#include <stdio.h>

enum estado_civil {casado, soltero, viudo, separado, divorciado, NSNC, estado_civil_TOPE };

enum meses { ENE=1, FEB, MAR, ABR, MAY, JUN, JUL, AGO, SEP, OCT, NOV, DIC, meses_TOPE };

char * estado_civil_nombre(int i)
{
  switch(i)
  {
    case casado: return "casado";
    case soltero: return "soltero";
    case viudo: return "viudo";
    case separado: return "separado";
    case divorciado: return "divorciado";
    case NSNC: return "no sabe";
    default: return "error";
  }
}

char * mes_nombre(int i)
{
  switch(i)
  {
    case ENE: return "enero";
    case FEB: return "febrero";
    case MAR: return "marzo";
    case ABR: return "abril";
    case MAY: return "mayo";
    case JUN: return "junio";
    case JUL: return "julio";
    case AGO: return "agosto";
    case SEP: return "septiembre";
    case OCT: return "octubre";
    case NOV: return "noviembre";
    case DIC: return "diciembre";
    default: return "error";
  }
}

int main()
{
  int i;

  for(i=casado; i < estado_civil_TOPE; i++)
  {
    printf("El estado civil %s vale %d\n", estado_civil_nombre(i), i);
  }

  for(i=ENE; i < meses_TOPE; i++)
  {
    printf("El mes %s vale %d\n", mes_nombre(i), i);
  }
  return 0;
}
