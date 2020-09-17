#include "scanner.h"

int cantIdentificadores = 0;
int cantConstantes = 0;
int cantNumerales= 0;
int cantErrores = 0;
Token token; //TODO: TYPEDEF ENUM // nevermind


int main() {

	printf("Los valores obtenidos de analizar los datos de prueba son: \n");

	do
	    {
	        token = scanner();
	        switch(token)
	        {
	            case IDENTIFICADOR:
	            printf("identificador\n");
	            cantIdentificadores++;
	            break;
	            case CONSTANTE:
	            printf("constante entera\n");
	            cantConstantes++;
	            break;
	            case NUMERAL:
	            printf("numeral\n");
	            cantNumerales++;
	            break;
	            case ERROR:
	            printf("error\n");
	            cantErrores++;
	            break;
	            case FDT:
	            break;
	            }
	    }while(token != FDT);

	    printf("----\n");
	    printf("Totales\n");
	    printf("Identificadores: %d\n",cantIdentificadores);
	    printf("Constantes enteras: %d\n",cantConstantes);
	    printf("Numerales: %d\n",cantNumerales);
	    printf("Errores: %d\n",cantErrores);

	    return 0;
	}



/*
 char* path = "cadena.txt";
	FILE* archivo =  fopen( path, "r" );
	   if (!archivo)
	    {
	        printf("No se pudo abrir el archivo ");
	        return EXIT_FAILURE;
	    }

	   while (token != FDT)
	       {
	           token = scanner(archivo);
	           switch (token)
	           {
	           case IDENTIFICADOR:
	               printf("Identificador\n");
	               cantIdentificadores++;
	               break;
	           case CONSTANTE:
	               printf("Constante entera\n");
	               cantConstantes++;
	               break;
	           case NUMERAL:
	        	   printf("Numeral");
				   cantNumerales++;
	        	   break;
	           case ERROR:
	               printf("Error\n");
	               cantErrores++;
	               break;
	           }
	       }



    char cadena[100];
    int length;
    int i = 0;
    char token[50] = "TOKEN";
    int res;

    printf( "Enter a value :");
    gets(cadena);

    length = strlen(cadena);

    printf( "\nYou entered: ");
    puts(cadena);

    while(i < length) {
        printf( "\nletter: ");
        if(isspace(cadena[i]) != 0) {
            res = scan_token(token, i);
        } else {
            putchar(cadena[i]);
            printf("%d", i);
        }
        i++;
    }

    return 0;
}
*/
