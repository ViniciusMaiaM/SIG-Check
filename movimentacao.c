#include <stdio.h>
#include <stdlib.h>
#include "movimentacao.h"
    
void tela_gerencia(void) {
    system("clear||cls");
    char tipo[20];
    int num_cheque;
    char id[19];
    char cod_banco[3]; //verificar qual a melhor maneira de validar esse, a data e o num_cheque, com char ou int
    int valor_depositado;
    char data[10];
    int valor_pago;
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
    printf("|          - - - - Cadastrar cheque  - - - -         |\n");
    printf("|                                                    |\n");
    printf("|          Tipo (A vista || A prazo): ");
    scanf("%[A-Z a-z]",tipo);
    printf("|          Numero do cheque: ");
    scanf("%d",&num_cheque);
    printf("|          Codigo do banco: ");
    scanf("%[0-9]",cod_banco);
    printf("|          ID do usuario: ");
    scanf("%[A-Z a-z., 0-9]",id);
    printf("|          Data do vendimento(dd/mm/aaaa): ");
    scanf("%[0-9 /]",data);
    printf("|          Valor Pago: ");
    scanf("%d",&valor_pago);
    printf("|          Valor Depositado: ");
    scanf("%d",&valor_depositado);
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}



void tela_pesquisar_cheque(void) {
    system("clear||cls");
    int num_cheque;
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
    printf("|          - - - - Pesquisar cheque - - - -          |\n");
    printf("|                                                    |\n");
    printf("|   Informe o Numero do cheque (apenas numeros): ");
    scanf("%d",&num_cheque);
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}


void tela_alterar_cheque(void) {
    system("clear||cls");
    int num_cheque;
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
    printf("|          - - - - Alterar cheque - - - -            |\n");
    printf("|                                                    |\n");
    printf("|   Informe o Numero do cheque (apenas numeros): ");
    scanf("%d",&num_cheque);
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}


void tela_excluir_cheque(void) {
    system("clear||cls");
    int num_cheque;
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
    printf("|          - - - - Excluir cheque - - - -            |\n");
    printf("|                                                    |\n");
    printf("|   Informe o Numero do cheque (apenas numeros): ");
    scanf("%d",&num_cheque);
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
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
