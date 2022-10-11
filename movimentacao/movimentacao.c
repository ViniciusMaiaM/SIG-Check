#include <stdio.h>
#include <stdlib.h>
#include "movimentacao.h"
#include "../aux/aux.h"

void escolha_tela(char escolha) //cadastro de cheque
{ 
    switch (escolha)
    {
        case '1':
            relatorio_movimento();
            break;
        
        case '2':
            tela_pesquisar_cheque();
            break;
    
        default:
            printf("Por favor insira uma opcao valida.\n");
            break;
    }
}

void relatorio_movimento(void) { //Ainda vamos criar uma indicacao de caminnhos e validacoes
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatório movimenta  - - - -      \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Nome:Thamiris                             \n");
    printf("          Valor do cheque:300.00                    \n");
    printf("          Receptor do cheque:Italo                  \n");
    printf("____________________________________________________\n");
    printf("          Nome:Flavius                              \n");
    printf("          Valor do cheque:150.00                    \n");
    printf("          Receptor do cheque:Vinicius               \n");
    printf("____________________________________________________\n");
    printf("          Nome:Italo                                \n");
    printf("          Valor do cheque:386.00                    \n");
    printf("          Receptor do cheque:Flavius                \n");
    printf("____________________________________________________\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}

void tela_movimenta(void){
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Movimentacao - - -             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Relatorio geral                    \n");
    printf("             2 - Pesquisar movimentação             \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolha_tela(escolha);
}



void tela_pesquisar_cheque(void) {
    system("clear||cls");
    int num_cheque;
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("         - - - - Pesquisar Movimentação - - - -     \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("   Informe o Número do cheque (apenas números): ");
    scanf("%d",&num_cheque);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}

/*

void tela_movimenta(void) { //Ainda vamos criar uma indicacao de caminnhos e validacoes
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    

void tela_alterar_cheque(void) {
    system("clear||cls");
    int num_cheque;
    printf("\n");
    printf(" ____________________________________________________ \n");
    printf("                                                    \n");
    printf("    Universidade Federal do Rio Grande do Norte     \n");
    printf("            Centro de Ensino Superior               \n");
    printf("     Departamento de Computacao e Tecnologia        \n");
    printf("         Disciplina DCT1106 -- Programacao          \n");
    printf("                Projeto SIG-Check                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Alterar cheque - - - -            \n");
    printf("                                                    \n");
    printf("   Informe o Numero do cheque (apenas numeros): ");
    scanf("%d",&num_cheque);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}


void tela_excluir_cheque(void) {
    system("clear||cls");
    int num_cheque;
    printf("\n");
    printf("____________________________________________________ \n");
    printf("                                                    \n");
    printf("    Universidade Federal do Rio Grande do Norte     \n");
    printf("            Centro de Ensino Superior               \n");
    printf("     Departamento de Computacao e Tecnologia        \n");
    printf("         Disciplina DCT1106 -- Programacao          \n");
    printf("                Projeto SIG-Check                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Excluir cheque - - - -            \n");
    printf("                                                    \n");
    printf("   Informe o Numero do cheque (apenas numeros): ");
    scanf("%d",&num_cheque);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}


void tela_lucros(void) {
    system("clear||cls");
    printf("\n");
    printf(" ____________________________________________________ \n");
    printf("|                                                    |\n");
    printf("|    Universidade Federal do Rio Grande do Norte     |\n");
    printf("|            Centro de Ensino Superior               |\n");
    printf("|     Departamento de Computacao e Tecnologia        |\n");
    printf("|         Disciplina DCT1106 -- Programacao          |\n");
    printf("|                Projeto SIG-Check                   |\n");
    printf("|____________________________________________________|\n");
    printf("|                                                    |\n");
    printf("|         - - - - Caixa lucros - - - -               |\n");
    printf("|                                                    |\n");
    printf("|              Saldo:                                |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}
*/ 
