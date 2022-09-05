#include <stdio.h>
/*
Modulo ainda em desenvolvimento

void tela_gerencia(void) {
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
    printf("|          - - - - Modulo gerencia - - - -           |\n");
    printf("|                                                    |\n");
    printf("|          Pagar cheque                              |\n");
    printf("|          Caixa (lucro)                             |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}



void tela_pesquisar_cheque(void) {
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
    printf("|          - - - - Pesquisar cheque - - - -          |\n");
    printf("|                                                    |\n");
    printf("|   Informe o Numero do cheque (apenas numeros):     |\n");
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
    printf("|   Informe o Numero do cheque (apenas numeros):     |\n");
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
    printf("|   Informe o Numero do cheque (apenas numeros):     |\n");
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


void tela_pagar_cheque(void) {
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
    printf("|          - - - - Pagar cheque - - - -              |\n");
    printf("|                                                    |\n");
    printf("|          ID do usuario:                            |\n");
    printf("|          Codigo do banco:                          |\n");
    printf("|          Numero do cheque:                         |\n");
    printf("|          Valor do cheque:                          |\n");
    printf("|          Data do pagamento:                        |\n");
    printf("|          Valor a pagar:                            |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}

void cadastrar_cheque(void) {
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
    printf("|          Tipo (A vista || A prazo):                |\n");
    printf("|          Numero do cheque:                         |\n");
    printf("|          Codigo do banco:                          |\n");
    printf("|          ID do usuario:                            |\n");
    printf("|          Data do vendimento(dd/mm/aaaa):           |\n");
    printf("|          Valor:                                    |\n");
    printf("|          Quantidade de parcelas                    |\n");
    printf("|                                                    |\n");
    printf("|                                                    |\n");
    printf("|____________________________________________________|\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}
*/