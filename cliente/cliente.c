#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "../aux/aux.h"
#include <string.h>
#include <math.h>

void escolha_cliente (char escolha) //cadastro de cheque
{ 
    switch (escolha)
    {
        case '1':
        cadastro_cliente();
        break;
        
        case '2':
        pesquisar_cliente();
        break;
        
        case '3': 
        excluir_cliente();
        break;
        
        case '4':
        relatorio_cliente();
        break;

        default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}


void tela_cliente(void) {
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Cliente - - - -                \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar Cliente                  \n");
    printf("             2 - Pesquisar Cliente                  \n");
    printf("             3 - Excluir   Cliente                  \n");
    printf("             4 - Relatório Cliente                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolha_cliente(escolha);
} 


void cadastro_cliente(void){
    char nome[30];
    char cpf[15];
    char celular[19];
    char email[30];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("          Nome completo: ");
    scanf("%[A-Z a-z]",nome);
    getchar();
    
    do{
        printf("          CPF: ");
        scanf("%s",cpf);
        getchar();
    }while(!valida_cpf(cpf));

    do{
        printf("          Celular (apenas números | Insira DDD): ");
        scanf("%[0-9]",celular);
        getchar();
    }while(!valida_cel(celular));
    
    do{
        printf("          Email: ");
        fgets(email,30,stdin);
    }while(!valida_email(email));

    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
}

void pesquisar_cliente(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
    system("clear||cls");
    char nome[30];
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Pesquisar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("           Informe o nome: ");
    scanf("%s",nome);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
}

void excluir_cliente(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
    system("clear||cls");
    char nome[30];
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Excluir cliente - - - -           \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("           Informe o nome: ");
    scanf("%s",nome);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nCliente %s excluido com sucesso!",nome);
    printf("\nPressione enter para continuar!\n");
    getchar();
}

void relatorio_cliente(){
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatório cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Nome: Vinicius\n");
    printf("          CPF: 123.456.789-10\n");
    printf("          Celular: 912345678\n");
    printf("          Email: vinicius.maia.123@ufrn.edu.br\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Nome: Thamiris\n");
    printf("          CPF: 123.456.789-10\n");
    printf("          Celular: 912345678\n");
    printf("          Email: thamiris.123@ufrn.edu.br\n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
}

