#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "../aux/aux.h"
#include "../cheque/cheque.h"
#include "../cliente/cliente.h"

void escolhe_relatorio(char escolha) // cadastro de cheque
{
    switch (escolha)
    {
    case '1':
        relatorio_cliente();
        break;

    case '2':
        relatorio_cheque();
        break;

    case '3':
        break;

    default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}

void tela_relatorio(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Relatorio - - - -              \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Relatorio de clientes              \n");
    printf("             2 - Relatorio de cheques               \n");
    printf("             3 - Relatorio de caixa                 \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolhe_relatorio(escolha);
}

void relatorio_cliente(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Cliente - - - -              \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem de todos                  \n");
    printf("             2 - Listagem por status                \n");
    printf("             3 - Listagem por nascimento            \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolhe_cliente(escolha);
}

void escolhe_cliente(char escolha)
{
    switch (escolha)
    {
    case '1':
        lista_cliente();
        break;

    case '2':
        break;

    case '3':
        break;

    default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}

void lista_cliente(void)
{
    system("clear||cls");
    int cont = 0;
    FILE *fp;
    Cliente *cli;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Listagem - - - -                  \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    cli = (Cliente *)malloc(sizeof(Cliente));
    fp = fopen("cliente.txt", "rt");

    if (fp == NULL)
    {
        printf("\nNão foi possível abrir o arquivo.\n");
    }

    else
    {
        while (fread(cli, sizeof(Cliente), 1, fp))
        {
            if (cli->status != 'x')
            {
                exibe_cliente(cli);
                cont++;
            }
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d cliente(s) cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }

    espera();
    fclose(fp);
    free(cli);
}

void relatorio_cheque(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Cheque - - - -               \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem de todos                  \n");
    printf("             2 - Listagem por cpf                   \n");
    printf("             3 - Listagem por valor                 \n");
    printf("             4 - Listagem por data                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolhe_cheque(escolha);
}

void escolhe_cheque(char escolha)
{
    switch (escolha)
    {
    case '1':
        lista_cheque();
        break;

    case '2':
        lista_cpf();
        break;

    case '3':
        break;

    default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}

void lista_cheque()
{
    system("clear||cls");
    FILE *fp;
    Cheque *che;
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Listagem - - - -                  \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel iniciar a listagem");
    }

    while (fread(che, sizeof(Cheque), 1, fp))
    {
        if (che->status != 'x')
        {
            exibe_cheque(che);
            cont++;
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d cheque(s) cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cheque(s) cadastrados!");
    }
    espera();
    fclose(fp);
    free(che);
}

void lista_cpf(void){
    system("clear||cls");
    FILE* fp;
    Cheque* che;
    char cpf[30];
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Listagem por cpf - - - -          \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");
    printf("          Insira o cpf para ser buscado: ");
    scanf(" %[0-9]", cpf);
    getchar();
    if(fp == NULL){
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
    }

    while(!feof(fp)){
        fread(che,sizeof(Cheque),1,fp);
        if(strcmp(che->cpf_cliente,cpf) == 0 && (che->status != 'x')){
            exibe_cheque(che);
            cont++;
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d cheque(s) cadastrados com esse cpf!\n", cont);
    }

    else
    {
        printf("\nVocê não possui cheque(s) cadastrados com esse cpf!\n");
    }

    espera();
    fclose(fp);
    free(che);
}
