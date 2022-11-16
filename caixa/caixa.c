#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "caixa.h"
#include "../aux/aux.h"


void escolha_caixa(char escolha){
    switch (escolha)
    {
    case '1':
        break;
    
    default:
        break;
    }
}

void tela_cliente(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Caixa - - - -                  \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar Caixa                    \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolha_caixa(escolha);
}

