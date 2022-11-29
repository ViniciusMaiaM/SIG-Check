#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //tem que incluir string e math
#include <math.h>
#include <time.h> //biblioteca de data e hora
#include "cheque.h"
#include "../aux/aux.h"

void muda_tela_cheque(char escolha) // cadastro de cheque
{
    Cheque *che;
    switch (escolha)
    {
    case '1':
        che = cadastrar_cheque();
        // if (!valida_cheque(che))
        // {
        //     printf("\nO cheque que você quer cadastrar já existe em nossos arquivos.\nPor favor tente novamente!");
        //     espera();
        //     break;
        // }
        grava_cheque(che);
        free(che);
        break;

    case '2':
        che = busca_cheque();
        exibe_cheque(che);
        free(che);
        break;

    case '3':
        che = busca_cheque();
        excluir_cheque(che);
        free(che);
        break;

    case '4':
        che = busca_cheque();
        att_cheque(che);
        free(che);
        break;

    case '5':
        lista_cheque();

    default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}

void tela_cheque(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Cheque - - - -                 \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Cadastrar cheque                   \n");
    printf("             2 - Pesquisar cheque                   \n");
    printf("             3 - Excluir cheque                     \n");
    printf("             4 - Atualizar cheque                   \n");
    printf("             5 - Relatório                          \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    muda_tela_cheque(escolha);
}

Cheque *cadastrar_cheque(void)
{ // Tela que recebe informacoes iniciais do user, precisamos criar validacoes
    Cheque *che;
    che = (Cheque *)malloc(sizeof(Cheque));
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cheque - - - -          \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    do
    {
        printf("          Número agência: ");
        scanf(" %[0-9]", che->agencia);
        getchar();
    } while (!valida_dig(che->agencia));
    
    do
    {
        printf("          Número conta: ");
        scanf(" %[0-9]", che->num_conta);
        getchar();
    } while (!valida_dig(che->num_conta));

    do
    {
        printf("          Código do banco: ");
        scanf(" %[0-9]", che->cod_banco);
        getchar();
    } while (!valida_dig(che->cod_banco));



    printf("          Valor do cheque: ");
    scanf("%d", &che->valor);
    getchar();

    do
    {
        printf("          Data para ser descontado: ");
        scanf(" %[0-9 / -]", che->data);
        getchar();
    } while (!data_str(che->data));

    che->id = def_id();
    printf("\tSeu id: %d",che->id);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    espera();
    che->status = 'c';
    return che;
}

void grava_cheque(Cheque *che)
{
    FILE *fp;
    fp = fopen("cheque.txt", "at");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }
    
    else{
        fwrite(che, sizeof(Cheque), 1, fp);
        fclose(fp);
    }
}

Cheque *busca_cheque()
{
    FILE *fp;
    Cheque *che;
    char num_conta[10];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Buscar Cheque - - - -             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("           Informe o número do cheque: ");
    scanf("%[0-9]", num_conta);
    getchar();
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(che, sizeof(Cheque), 1, fp);
        if (strcmp(che->num_conta, num_conta) == 0 && (che->status != 'x'))
        { /*Verifica se o código é igual e o status*/
            fclose(fp);
            return che;
        }
    }

    fclose(fp);
    return NULL;
}

void exibe_cheque(Cheque *che)
{
    char situacao[20];
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatório Cheque - - - -          \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    if ((che == NULL) || che->status == 'x')
    {
        printf("\nCheque não encontrado\n");
    }

    else
    {
        printf("\nAgência: %s\n", che->agencia);
        printf("Número Cheque: %d\n", che->id);
        printf("Código Banco: %s\n", che->cod_banco);
        printf("Data de postagem: %s\n", che->data);
        printf("Número da conta: %s\n", che->num_conta);
        printf("Valor do cheque: %d\n", che->valor);

        if (che->status == 'c')
        {
            strcpy(situacao, "Cadastrado");
        }

        else if (che->status == 'p')
        {
            strcpy(situacao, "Pago");
        }

        else
        {
            strcpy(situacao, "Não reconhecido");
        }

        printf("Situação do Cheque: %s", situacao);
    }
    printf("\n____________________________________________________\n");
    espera();
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
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
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

void excluir_cheque(Cheque *che)
{
    FILE *fp;
    Cheque *che_arq;
    int achou = 0;
    char escolha;

    if (che == NULL)
    {
        printf("\nCheque não encontrado!\n");
    }

    else
    {
        che_arq = (Cheque *)malloc(sizeof(Cheque));
        fp = fopen("cheque.txt", "r+t");
        if (fp == NULL)
        {
            printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        }

        while (!feof(fp))
        {
            fread(che_arq, sizeof(Cheque), 1, fp);
            if ((strcmp(che_arq->num_conta, che->num_conta) == 0 && (che_arq->status != 'x')))
            {
                exibe_cheque(che);
                printf("\nEsse é o cheque que você quer excluir(S/N)? ");
                scanf("%c", &escolha);
                achou = 1;
                if (escolha == 'S' || escolha == 's')
                {
                    che_arq->status = 'x';
                    fseek(fp, -1 * sizeof(Cheque), SEEK_CUR);
                    fwrite(che_arq, sizeof(Cheque), 1, fp);
                    printf("\nCheque excluído!\n");
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
            printf("\nCheque não encontrado\n");
        }

        fclose(fp);
        free(che_arq);
    }
    espera();
}

void att_cheque(Cheque *che)
{
    FILE *fp;
    char resp;
    char escolha;

    if ((che == NULL) || (che->status == 'x'))
    {
        printf("\nCheque não encontrado\n");
    }

    fp = fopen("cheque.txt", "r+t");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }

    exibe_cheque(che);
    printf("\nEste é o cheque que você quer atualizar(S/s)? ");
    scanf("%c", &resp);
    getchar();

    if (resp == 'S' || resp == 's')
    {
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Agência                            \n");
        printf("             2 - Número Cheque                      \n");
        printf("             3 - Código Banco                       \n");
        printf("             4 - Data                               \n");
        printf("             5 - Número conta                       \n");
        printf("             6 - Valor                              \n");
        printf("             7 - Tudo                               \n");
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
                printf("Informe a agência: ");
                scanf(" %[0-9]", che->agencia);
                printf("\nCheque editado com sucesso!\n");
                break;

            case '2':
                // printf("Informe a o número do cheque: ");
                // scanf(" %[0-9]", che->id);
                // printf("\nCheque editado com sucesso!\n");
                break;

            case '3':
                printf("Informe o código do banco: ");
                scanf(" %[0-9]", che->cod_banco);
                printf("\nCheque editado com sucesso!\n");
                break;

            case '4':
                printf("Informe a data: ");
                scanf(" %[0-9]", che->data);
                printf("\nCheque editado com sucesso!\n");
                break;

            case '5':
                printf("Informe o número da conta: ");
                scanf(" %[0-9]", che->num_conta);
                printf("\nCheque editado com sucesso!\n");
                break;

            case '6':
                printf("Informe o valor: ");
                scanf(" %d", &che->valor);
                printf("\nCheque editado com sucesso!\n");
                break;

            case '7':
                printf("\nInforme a agência: ");
                scanf(" %[0-9]", che->agencia);
                // printf("\nInforme a o número do cheque: ");
                // scanf(" %[0-9]", che->id);
                printf("\nInforme o código do banco: ");
                scanf(" %[0-9]", che->cod_banco);
                printf("\nInforme a data: ");
                scanf(" %[0-9]", che->data);
                printf("\nInforme o número da conta: ");
                scanf(" %[0-9]", che->num_conta);
                printf("\nInforme o valor: ");
                scanf(" %d", &che->valor);
                printf("\nCheque editado com sucesso!\n");
                break;

            default:
                printf("\nPor favor insira uma opcao valida.\n");
                break;
            }
            escolha = '0';
        }
        fseek(fp, (-1) * sizeof(Cheque), SEEK_CUR);
        fwrite(che, sizeof(Cheque), 1, fp);
    }

    else
    {
        printf("\nOk, os dados não foram alterados!\n");
    }

    fclose(fp);
}

int valida_cheque(Cheque *che)
{
    FILE *fp;
    Cheque *che_arq;

    che_arq = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }

    while (!feof(fp))
    {
        fread(che_arq, sizeof(Cheque), 1, fp);
        if (strcmp(che->num_conta, che_arq->num_conta) == 0 && (che_arq->status != 'x'))
        {
            return 0;
        }
    }

    return 1;
}

int def_id(){
    FILE* fp;
    Cheque* che_arq;
    che_arq = (Cheque*) malloc(sizeof(Cheque));
    fp = fopen("cheque.txt","rt");

    if (fp == NULL){
        return 1;
    }

    else{
        fseek(fp, -1*sizeof(Cheque), SEEK_END);
        fread(che_arq,sizeof(Cheque),1,fp);
        return (che_arq->id + 1);
    }
}
