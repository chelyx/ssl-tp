#include "scanner.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



const bool estadosTerminales[9] = {false,false,false,false,true,true,true,true,true};

static int tabla[4][6] = {
    {1 , 2 , 7 , 0 , 3 , 4 },
    {1 , 1 , 5 , 5 , 5 , 5 },
    {6 , 2 , 6 , 6 , 6 , 6 },
    {8 , 8 , 8 , 8 , 3 , 8 }
    };

bool esTerminal(int estado) {
	return estadosTerminales[estado];
}

int analizarEstado(char c, int estado_presente) {
  if(isalpha(c))
    return tabla[estado_presente][LETRA];
  else if(isdigit(c))
    return tabla[estado_presente][NUMERO];
  else if(c == '#')
    return tabla[estado_presente][NUMERAAL];
  else if(isspace(c))
    return tabla[estado_presente][ESPACIO];
  else if (c == EOF )
    return tabla[estado_presente][FDC];
  else
    return tabla[estado_presente][OTRO];
}

Token clasificarToken(char c, int estado_presente) {
    switch(estado_presente) {
		case 4:
			return FDT;

		case 5:
		   ungetc(c,stdin);
		   return IDENTIFICADOR;

		case 6:
		   ungetc(c,stdin);
		   return CONSTANTE;

		case 7:
			return NUMERAL;

		default:
			ungetc(c,stdin);
			return ERROR;
	}

}

Token scanner() {
	int estado_presente = 0;
	char c;

	while(!esTerminal(estado_presente)) {
 	  c  = getchar();
 	  estado_presente = analizarEstado(c, estado_presente);
	 }

	return clasificarToken(c, estado_presente);
 }
