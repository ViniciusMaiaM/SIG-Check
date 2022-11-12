#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "../aux/aux.h"
#include <string.h>
#include <math.h>

void escolha_cliente(char escolha) // cadastro de cheque
{
    Cliente *cli;
    switch (escolha)
    {
    case '1':
        cli = cadastro_cliente();
        grava_cliente(cli);
        free(cli);
        break;

    case '2':
        cli = busca_cliente();
        exibe_cliente(cli);
        break;

    case '3':
        cli = busca_cliente();
        excluir_cliente(cli);
        free(cli);
        break;

    case '4':
        cli = busca_cliente();
        att_cliente(cli);
        free(cli);
        break;

    case '5':
        lista_cliente();
        break;

    default:
        printf("Por favor insira uma opcao valida.\n");
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
    printf("             - - - - Cliente - - - -                \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar Cliente                  \n");
    printf("             2 - Pesquisar Cliente                  \n");
    printf("             3 - Excluir   Cliente                  \n");
    printf("             4 - Atualizar Cliente                  \n");
    printf("             5 - Relatório Cliente                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolha_cliente(escolha);
}

Cliente *cadastro_cliente(void)
{
    Cliente *cli;
    cli = (Cliente *)malloc(sizeof(Cliente));
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("          Nome completo: ");
    scanf(" %30[^\n]", cli->nome_cliente);
    getchar();

    do
    {
        printf("          CPF: ");
        scanf("%[0-9]", cli->cpf_cliente);
        getchar();
    } while (!valida_cpf(cli->cpf_cliente));

    do
    {
        printf("          Celular (apenas números | Insira DDD): ");
        scanf(" %[0-9]", cli->cel_cliente);
        getchar();
    } while (!valida_cel(cli->cel_cliente));

    do
    {
        printf("          Email: ");
        fgets(cli->email_cliente, 30, stdin);
    } while (!valida_email(cli->email_cliente));

    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
    cli->status = 'c';
    return cli;
}

void excluir_cliente(Cliente *cli)
{
    FILE *fp;
    Cliente *cli_arq;
    int achou = 0;
    char escolha;

    if (cli == NULL)
    {
        printf("\nCliente não encontrado!\n");
    }

    else
    {
        cli_arq = (Cliente *)malloc(sizeof(Cliente));
        fp = fopen("cliente.txt", "r+t");
        if (fp == NULL)
        {
            printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
            exit(1);
        }

        while (!feof(fp))
        {

            fread(cli_arq, sizeof(Cliente), 1, fp);
            if ((strcmp(cli_arq->cpf_cliente, cli->cpf_cliente) == 0 && (cli_arq->status != 'x')))
            {
                exibe_cliente(cli);
                printf("\nEsse é o cliente que você quer apagar(S/s)? ");
                scanf(" %c", &escolha);
                achou = 1;

                if (escolha == 'S' || escolha == 's')
                {
                    cli_arq->status = 'x';
                    fseek(fp, -1 * sizeof(Cliente), SEEK_CUR);
                    fwrite(cli_arq, sizeof(Cliente), 1, fp);
                    printf("\nCliente excluído!\n");
                    break;
                }

                else
                {
                    break;
                }
            }
        }

        if (!achou)
        {
            printf("\nCliente não encontrado\n");
        }

        fclose(fp);
        free(cli_arq);
    }
    printf("\nPressione enter...");
    getchar();
}

void exibe_cliente(Cliente *cli)
{
    char situacao[20];
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatório Cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

    if ((cli == NULL) || cli->status == 'x')
    {
        printf("\nCliente não encontrado\n");
    }

    else
    {
        printf("\nNome: %s\n", cli->nome_cliente);
        printf("CPF: %s\n", cli->cpf_cliente);
        printf("Celular: %s\n", cli->cel_cliente);
        printf("Email: %s\n", cli->email_cliente);

        if (cli->status == 'c')
        {
            strcpy(situacao, "Cadastrado");
        }

        else
        {
            strcpy(situacao, "Não reconhecido");
        }

        printf("Situação do cliente: %s", situacao);
    }
    printf("\n____________________________________________________\n");
    printf("\nPressione enter...\n");
    getchar();
}

void grava_cliente(Cliente *cli)
{
    FILE *fp;
    fp = fopen("cliente.txt", "at");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    fwrite(cli, sizeof(Cliente), 1, fp);
    fclose(fp);
}

Cliente *busca_cliente()
{
    FILE *fp;
    Cliente *cli;
    char cpf[15];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Buscar Cliente - - - -             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("           Informe o número do cpf: ");
    scanf("%[0-9]", cpf);
    getchar();
    cli = (Cliente *)malloc(sizeof(Cliente));
    fp = fopen("cliente.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cli, sizeof(Cliente), 1, fp);
        if (strcmp(cli->cpf_cliente, cpf) == 0 && (cli->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            return cli;
        }
    }

    fclose(fp);
    return NULL;
}

void lista_cliente(void)
{
    system("clear||cls");
    int cont = 0;
    FILE *fp;
    Cliente *cli;
    cli = (Cliente *)malloc(sizeof(Cliente));
    fp = fopen("cliente.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (fread(cli, sizeof(Cliente), 1, fp))
    {
        if (cli->status != 'x')
        {
            exibe_cliente(cli);
            cont++;
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

    printf("\nPressione enter...");
    getchar();
    fclose(fp);
    free(cli);
}

void att_cliente(Cliente *cli)
{
    FILE *fp;
    char resp;
    char escolha;

    if ((cli == NULL) || (cli->status == 'x'))
    {
        printf("\nCliente não encontrado\n");
        exit(1);
    }

    fp = fopen("cliente.txt", "r+t");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    exibe_cliente(cli);
    printf("\nEste é o cliente que você quer(S/s)? ");
    scanf("%c", &resp);
    getchar();

    if (resp == 'S' || resp == 's')
    {
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Nome                               \n");
        printf("             2 - Cpf                                \n");
        printf("             3 - Celular                            \n");
        printf("             4 - Email                              \n");
        printf("             5 - Tudo                               \n");
        printf("             0 - Voltar                             \n");
        printf("                                                    \n");
        printf("____________________________________________________\n");
        printf("             O que você quer atualizar: ");
        scanf("%c", &escolha);
        getchar();

        while (escolha != '0')
        {
            switch (escolha)
            {
            case '1':
                printf("\nInforme o nome: ");
                scanf(" %30[^\n]", cli->nome_cliente);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '2':
                printf("\nInforme o cpf: ");
                scanf(" %30[^\n]", cli->cpf_cliente);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '3':
                printf("\nInforme o celular: ");
                scanf(" %[0-9]", cli->cel_cliente);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '4':
                printf("\nInforme o email: ");
                scanf(" %30[^\n]", cli->email_cliente);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '5':
                printf("\nInforme o nome: ");
                scanf(" %30[^\n]", cli->nome_cliente);
                printf("\nInforme o cpf: ");
                scanf(" %30[^\n]", cli->cpf_cliente);
                printf("\nInforme o celular: ");
                scanf(" %[0-9]", cli->cel_cliente);
                printf("\nInforme o email: ");
                scanf(" %30[^\n]", cli->email_cliente);
                printf("\nCliente editado com sucesso!\n");
                break;

            default:
                printf("\nPor favor insira uma opcao valida.\n");
                break;
            }
            escolha = '0';
        }
        fseek(fp, (-1) * sizeof(Cliente), SEEK_CUR);
        fwrite(cli, sizeof(Cliente), 1, fp);
        printf("\nCliente editado com sucesso!\n");
    }

    else
    {
        printf("\nOk, os dados não foram alterados!\n");
    }

    fclose(fp);
}
