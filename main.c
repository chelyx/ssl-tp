#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
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
