#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "../aux/aux.h"
#include <string.h>
#include <math.h>

void escolha_cliente (char escolha) //cadastro de cheque
{ 
    Cliente* cli;
    switch (escolha)
    {
        case '1':
        cli = cadastro_cliente();
        grava_cliente(cli);
        free(cli);
        break;
        
        case '2':
        cli = busca_cliente();

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


Cliente* cadastro_cliente(void){
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("          Nome completo: ");
    scanf("%30[^\n]",cli->nome_cliente);
    getchar();
    
    do{
        printf("          CPF: ");
        scanf("%s",cli->cpf_cliente);
        getchar();
    }while(!valida_cpf(cli->cpf_cliente));

    do{
        printf("          Celular (apenas números | Insira DDD): ");
        scanf("%[0-9]",cli->cel_cliente);
        getchar();
    }while(!valida_cel(cli->cel_cliente));
    
    do{
        printf("          Email: ");
        fgets(cli->email_cliente,30,stdin);
        getchar();
    }while(!valida_email(cli->email_cliente));

    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
    cli->status = 'c';
    return cli;
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

void relatorio_cliente(Cliente* cli){
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

void grava_cliente(Cliente* cli){
    FILE* fp;
    fp = fopen("cliente.txt","at");

    if(fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    fwrite(cli,sizeof(Cliente),1,fp);
    fclose(fp);
}

Cliente* busca_cliente(){
    FILE* fp;
    Cliente* cli;
    char cpf[15];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Buscar Cheque - - - -             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("           Informe o número do cheque: ");
    scanf("%[0-9]",cpf);
    getchar();
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("cliente.txt","rt");

    if(fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }  
    while(!feof(fp)){ //Busca até o final do arquivo
        fread(cli, sizeof(Cliente),1,fp);
        if(strcmp(cli->cpf_cliente,cpf) == 0 && (cli->cpf_cliente != 'x')){ /*Verifica se o código é igual e o status*/
            fclose(fp);
            return cli;
        }

    }

    fclose(fp);
    return NULL;
}
