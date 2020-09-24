#ifndef SCANNER_H_INCLUDED
#define SCANNER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
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
int analizarEstado(char c);
Token clasificarToken(int estado_presente);
Token  scanner();


#endif