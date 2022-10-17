#include <stdio.h>
#include "aux.h"

char input(void) //função de input
{
    char n;
    printf("Insira sua escolha: ");
    scanf("%c", &n);
    getchar();
    return n; 
}