#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "scanner.h"
char caracter;
int estadoActual=0;


Token scanner(FILE* archivo)
{
	while(!stop(estado_actual)){
		caracter = fgetc(archivo);
		estadoActual = analizarCaracter(caracter)
	}
	
	aceptarToken(estado_actual);
	estado_actual = 0;
}
    
    bool stop(int estado)
{
	return estados[estado];
}

