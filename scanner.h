#include<stdio.h>
#include<stdlib.h>


const bool estadosTerminales[10] = {false,false,false,false,false,true,true,true,true,true};

typedef enum {
	CONSTANTE,
	IDENTIFICADOR,
	NUMERAL,
	ERROR,
	FDT
}Token;

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
    
int = scanner(FILE* archivo);
bool stop(int estado);
int scan_token(char* token, int hasta);

