#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdbool.h>

typedef enum {
	CONSTANTE,
	IDENTIFICADOR,
	NUMERAL,
	ERROR,
	FDT
}Token;

typedef enum{
	LETRA,
	NUMERO,
	NUMERAAL,
	ESPACIO,
	OTRO,
	FDC
}Caracter;

bool esTerminal(int estado);
int analizarEstado(char c, int estado_presente);
Token clasificarToken(char c, int estado_presente);
Token  scanner();


#endif
