#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

void invertir (int argc, char *str){

	printf("Nada \n");

}

void mayus (int argc, char *str){

	printf("Me indica que la funcion 'strupr' no esta definida pero inlcui la libreria correspondiente. \n");
	/*char *dest = NULL;
	dest = strupr(str);
	printf("%s \n",dest);*/
}

void minus (int argc, char *str){

	printf("Me indica que la funcion 'strlwr' no esta definida pero inlcui la libreria correspondiente. \n");
	/*char *dest = NULL;
	dest = strlwr(str);
	printf("%s \n",dest);*/
}

int main (int argc, char *argv[]){
	
	printf("%s \n",argv[1]);

	if (((((strcmp(argv[1],"-i") > 0) && (strcmp(argv[1],"-u") > 0))) && (((strcmp(argv[1],"-l") > 0) && (strcmp(argv[1],"--uppercase") > 0)))) && (((strcmp(argv[1],"--invert") > 0) && (strcmp(argv[1],"--uppercase") > 0))))
	{
		
		printf("El flag indicado es incorrecto. Los flags válidos son: -i, --invert, -u, --uppercase, -l y --lowercase. \n");

		return 2;
	}
	else
	{
		if (argc < 3)
		{
			printf("Se deben especificar al menos 2 strings a concatenar. \n");
			return 1;
		}
		else
		{
			char *str = NULL;
			printf("%s \n",str);
			for (int i = 2; i < argc; i++)
			{
				char *aux = argv[i];
				str = strcat(str,aux);
			}
			if((strcmp(argv[1],"-i") == 0) || ((strcmp(argv[1],"--invert") == 0)))
			{
				invertir(argc,str);

			}
			if((strcmp(argv[1],"-u") == 0) || ((strcmp(argv[1],"--uppercase") == 0)))
			{
				mayus(argc,str);
			}
			if((strcmp(argv[1],"-l") == 0) || ((strcmp(argv[1],"--lowercase") == 0)))
			{
				minus(argc,str);
			}
			return 0;
		}
	}
}
