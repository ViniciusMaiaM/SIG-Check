#include <stdio.h>
#include <stdlib.h>
#include "movimentacao.h"
#include "cheque.h"

void escolha_tela(char escolha) //cadastro de cheque
{ 
    switch (escolha)
    {
        case '1':
            tela_movimenta();
            break;
        
        case '2':
            tela_pesquisar_cheque();
            break;
    
        default:
            printf("Por favor insira uma opcao valida.\n");
            break;
    }
}





void tela_movimenta(void) { //Ainda vamos criar uma indicacao de caminnhos e validacoes
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("    Universidade Federal do Rio Grande do Norte     \n");
    printf("            Centro de Ensino Superior               \n");
    printf("     Departamento de Computacao e Tecnologia        \n");
    printf("         Disciplina DCT1106 -- Programacao          \n");
    printf("                Projeto SIG-Check                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatorio movimenta  - - - -      \n");
    printf("                                                    \n");
    printf("  Adicionar movimentacao geral de movimentacao      \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}

void tela_gerencia(void){
    char escolha;
    system("clear||cls");
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
    printf("             - - - - Movimentacao - - -             \n");
    printf("                                                    \n");
    printf("             1 - Relatorio geral                    \n");
    printf("             2 - Pesquisar movimentacao             \n");
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
    printf(" ____________________________________________________ \n");
    printf("                                                    \n");
    printf("    Universidade Federal do Rio Grande do Norte     \n");
    printf("            Centro de Ensino Superior               \n");
    printf("     Departamento de Computacao e Tecnologia        \n");
    printf("         Disciplina DCT1106 -- Programacao          \n");
    printf("                Projeto SIG-Check                   \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("         - - - - Pesquisar Movimentacao - - - -     \n");
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

/*
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