#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void trad ()
{
	int i = 0, j = 0, k = 0;
	char c, l[255], src[255], dest[255];
	c = getchar();
	printf("Ingrese palabra:\n");
	while ((c = getchar()) != '\n')
	{
		l[i] = c;
		i++;
	}
	printf("Ingrese letras a cambiar:\n");
	while ((c = getchar()) != '\n')
	{
		src[j] = c;
		j++;
	}
	
	printf("Ingrese letras que lo reemplazan:\n");
	while ((c = getchar()) != '\n')
	{
		dest[k] = c;
		k++;
	}
	int aux = 0, aux2 = 0;
	while ((l[aux] != '\n') && (aux <= i))
	{
		
		while ((src[aux2] != '\n') && (aux2 <= j))
		{
			if (l[aux] == src[aux2])
			{
				l[aux] = dest[aux2];
			}
			aux2++;
		}
		aux2 = 0;
		aux++;
	}
	
	for (int aux3 = 0; aux3 < i; aux3++)
	{
		printf("%c",l[aux3]);
	}
	printf("\n");
}

int main()
{
	char c;
	printf("Ingrese variante a realizar t | b \n");
	if ((c = getchar()) == 't')
	{
		printf("-t \n");
		trad();
		return 0;
	}
	else
		if ((c = getchar()) == 'b')
		{
			printf("-b \n");
			printf("No hay nada");
			return 0;
		}
		else
			printf("ERROR \n");
			return 1;

}
