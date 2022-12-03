#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "../aux/aux.h"
#include <string.h>
#include <math.h>
#include <unistd.h>

void escolha_cliente(char escolha) // cadastro de cheque
{
    Cliente *cli;
    switch (escolha)
    {
    case '1':
        cli = cadastro_cliente();
        // if (!valida_cliente(cli))
        // {
        //     printf("\nO cliente que você quer cadastrar já existe em nossos arquivos.\nPor favor tente novamente!");
        //     espera();
        //     break;
        // }
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
    char nome[100];
    char cpf[30];
    char cel[30];
    char email[100];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

    ler_nome(nome);
    strcpy(cli->nome_cliente, nome);

    ler_cpf(cpf);
    strcpy(cli->cpf_cliente, cpf);

    ler_cel(cel);
    strcpy(cli->cel_cliente, cel);

    ler_email(email);
    strcpy(cli->email_cliente, email);
    
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    espera();
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
            printf("\nOcorreu um erro na abertura do arquivo, não é possivel continuar o programa\n");
        }

        else {
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
        }

        if (!achou)
        {
            printf("\nCliente não encontrado\n");
        }

        fclose(fp);
        free(cli_arq);
    }
    espera();
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
    espera();
}

void grava_cliente(Cliente *cli)
{
    FILE *fp;
    fp = fopen("cliente.txt", "at");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }

    else{
        fwrite(cli, sizeof(Cliente), 1, fp);
        fclose(fp);
    }
}

Cliente *busca_cliente()
{
    FILE *fp;
    Cliente *cli;
    char cpf[30];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Buscar Cliente - - - -             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("           Informe o número do cpf: ");
    ler_cpf(cpf);
    cli = (Cliente *)malloc(sizeof(Cliente));
    fp = fopen("cliente.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }

    else{
        while (!feof(fp))
        { // Busca até o final do arquivo
            fread(cli, sizeof(Cliente), 1, fp);
            if (strcmp(cli->cpf_cliente, cpf) == 0 && (cli->status != 'x'))
            { /*Verifica se o código é igual e o status*/
                fclose(fp);
                return cli;
            }
        }
    }

    fclose(fp);
    return NULL;
}

void att_cliente(Cliente *cli)
{
    FILE *fp;
    char resp;
    char escolha;
    char nome[100];
    char cpf[30];
    char cel[30];
    char email[100];

    if ((cli == NULL) || (cli->status == 'x'))
    {
        printf("\nCliente não encontrado\n");
        resp = 'n';
    }

    fp = fopen("cliente.txt", "r+t");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        resp = 'n';
    }

    else{
        exibe_cliente(cli);
        printf("\nEste é o cliente que você quer(S/s)? ");
        scanf("%c", &resp);
        getchar();
    }

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
                ler_nome(nome);
                strcpy(cli->nome_cliente, nome);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '2':
                ler_cpf(cpf);
                strcpy(cli->cpf_cliente, cpf);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '3':
                ler_cel(cel);
                strcpy(cli->cel_cliente, cel);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '4':
                ler_email(email);
                strcpy(cli->email_cliente, email);
                printf("\nCliente editado com sucesso!\n");
                break;

            case '5':
                ler_nome(nome);
                strcpy(cli->nome_cliente, nome);
                ler_cpf(cpf);
                strcpy(cli->cpf_cliente, cpf);
                ler_cel(cel);
                strcpy(cli->cel_cliente, cel);
                ler_email(email);
                strcpy(cli->email_cliente, email);
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
    }

    else
    {
        printf("\nOk, os dados não foram alterados!\n");
    }
    espera();
    fclose(fp);
}

int valida_cliente(char* cpf)
{
    FILE *fp;
    Cliente *cli_arq;

    cli_arq = (Cliente *)malloc(sizeof(Cliente));
    fp = fopen("cliente.txt", "rt");
    while (!feof(fp))
    {
        fread(cli_arq, sizeof(Cliente), 1, fp);
        if (strcmp(cpf, cli_arq->cpf_cliente) == 0 && (cli_arq->status != 'x'))
        {
            printf("\n\tCpf já cadastradado\n");
            return 0;
        }
    }

    return 1;
}

void ler_nome(char *nome)
{
    printf("\n\tNome completo: ");
    scanf(" %30[^\n]", nome);
}

void ler_cpf(char *cpf)
{
    do
    {
        printf("\n\tCPF: ");
        scanf(" %[0-9]", cpf);
        getchar();
    } while (!((valida_cpf(cpf)) && (valida_cliente(cpf))));
}

void ler_cel(char *cel)
{
    do
    {
        printf("\n\tCelular (apenas números | Insira DDD): ");
        scanf(" %[0-9]", cel);
        getchar();
    } while (!valida_cel(cel));
}

void ler_email(char *email)
{
    do
    {
        printf("\n\tEmail: ");
        fgets(email, 30, stdin);
    } while (!valida_email(email));
}
