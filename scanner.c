
#include "scanner.h"


const bool estadosTerminales[10] = {false,false,false,false,false,true,true,true,true,true};

int estado_presente = 0;
char c;


static int tabla[10][6] = {
    {1 , 2 , 3 , 0 , 4 , 5 },
    {1 , 1 , 6 , 6 , 6 , 6 },
    {7 , 2 , 7 , 7 , 7 , 7 },
    {8 , 8 , 8 , 8 , 8 , 8 },
    {9 , 9 , 9 , 9 , 4 , 9 },
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    {99 ,99 ,99 ,99 ,99, 99},
    };

// Se le pasa un estado y devuelve si hay que seguir o parar (true/false)
bool stop(int estado){

	return estadosTerminales[estado];
}

// Cambia el estado del caracter segun la categoria a la que este pertenece
int cambiarEstado(char c)
{
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

    return tabla[estado_presente][OTRO];
}

// Funcion que recibe un estado, y si este es aceptor reporta el tipo de token

Token aceptarToken(int estado_presente)
{
    switch(estado_presente)
	{

		case 6:
               ungetc(c,stdin);
		       return IDENTIFICADOR;
		case 7:
		       ungetc(c,stdin);
		       return CONSTANTE;
		case 8:
				ungetc(c,stdin);
				return NUMERAL;
		case 9:
				ungetc(c,stdin);
				return ERROR;

	}
	return FDT;
}
// Funcionamiento scanner

Token scanner()
{
	do{
 	  c  = getchar();
 	  estado_presente = cambiarEstado(c);
	   }while(!stop(estado_presente));

	aceptarToken(estado_presente);
	estado_presente = 0;
}




/* Token scanner(FILE* archivo)
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
}*/

