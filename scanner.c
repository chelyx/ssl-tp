
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

bool esTerminal(int estado){
	return estadosTerminales[estado];
}

int analizarEstado(char c)
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
  else
    return tabla[estado_presente][OTRO];
}

Token clasificarToken(int estado_presente)
{
    switch(estado_presente)
	{

        case 6:
               ungetc(c,stdin);
		       return IDENTIFICADOR;

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
		default:
			return FDT;
	}

	 return FDT;

}

Token scanner()
{
	estado_presente = 0;

	do{
 	  c  = getchar();
 	  estado_presente = analizarEstado(c);
	 }while(!esTerminal(estado_presente));
	 aceptarToken(estado_presente);
	 estado_presente = 0;

}

	return clasificarToken(estado_presente);
}




