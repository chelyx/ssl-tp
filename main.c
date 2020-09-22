#include "scanner.h"

int cantIdentificadores = 0;
int cantConstantes = 0;
int cantNumerales= 0;
int cantErrores = 0;
Token token; //TODO: TYPEDEF ENUM // nevermind


int main() {


	printf("Ingrese la cadena: \n");
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
