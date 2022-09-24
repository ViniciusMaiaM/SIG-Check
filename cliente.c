#include <stdio.h>

void tela_cliente(void) {
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
    printf("             - - - - Cheque - - - -                 \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar Cliente                  \n");
    printf("             2 - Pesquisar Cliente                  \n");
    printf("             3 - Excluir   Cliente                  \n");
    printf("             4 - Relatorio Cliente                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    muda_tela_cheque(escolha);
} 
