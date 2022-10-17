#include <stdio.h>
#include <string.h>
#include "aux.h"

int ddd[27] = {11,21,27,31,41,47,51,61,62,63,65,67,68,69,71,79,81,82,83,84,85,86,91,92,95,96,98};

char input(void) //função de input
{
    char n;
    printf("Insira sua escolha: ");
    scanf("%c", &n);
    getchar();
    return n; 
}

int valida_cel(char celular[]){
    
    int tam = strlen(celular);
    int ddd = ((celular[0] - '0') *10) + (celular[1] - '0');

    if (tam != 11){
        return 0;
    }


    if(!busca_ddd(ddd)){
        return 0;
    }

    if(!busca_num(tam,celular)){
        return 0;
    }

    return 1;
}

int busca_ddd(int busca){
    int tam = sizeof(ddd)/sizeof(ddd[0]);
    for(int i = 0; i < tam;i++){
        if (ddd[i] == busca){
            return 1;
        }
    }
    return 0;
}

int busca_num(int tam, char celular[]){
    for(int i = 0; i < tam; i++){
        if(!(celular[i] >= '0' && celular[i] <= '9')){
            return 0;
        }
    }
    return 1;
}