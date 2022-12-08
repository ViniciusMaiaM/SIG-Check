#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //tem que incluir string e math
#include <math.h>
#include <time.h> //biblioteca de data e hora
#include "cheque.h"
#include "../aux/aux.h"
#include "../cliente/cliente.h"

void muda_tela_cheque(char escolha) // cadastro de cheque
{
    Cheque *che;
    switch (escolha)
    {
    case '1':
        che = cadastrar_cheque();
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
    do{
        do
        {
            printf("          CPF: ");
            scanf(" %[0-9]", che->cpf_cliente);
            getchar();
        } while (!valida_cpf(che->cpf_cliente));
        
        if(!valida_cli(che->cpf_cliente)){
            printf("\nCPF não cadastrado, por favor cadastre o cliente!");
            espera();
            Cliente* cli;
            cli = cadastro_cliente();
            grava_cliente(cli);
            free(cli);
            system("clear||cls");
        }

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
        scanf("%f", &che->valor);
        getchar();

        do
        {
            printf("          Data para ser descontado: ");
            scanf(" %[0-9 / -]", che->data_desconto);
            getchar();
        } while (!data_str(che->data_desconto,1));

        char* tempo = data_atual();
        strcpy(che->data_cadastro,tempo);
        
        che->num_cheque = def_num();
        printf("          Seu Número de cheque: %d\n",che->num_cheque);
        gera_id(che);
    }while(!(valida_cheque(che->id)));
    printf("          Id de cheque: %s",che->id);
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
    char id_bus[26];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Buscar Cheque - - - -             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("           Informe o número do cheque: ");
    scanf("%[0-9]", id_bus);
    getchar();
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar a busca");
        return NULL;
    }

    else{
        while (!feof(fp))
        { // Busca até o final do arquivo
            fread(che, sizeof(Cheque), 1, fp);
            if (strcmp(che->id, id_bus) == 0 && (che->status != 'x'))
            { /*Verifica se o código é igual e o status*/
                fclose(fp);
                return che;
            }
        }

        fclose(fp);
    }
    
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
        printf("Número da conta: %s\n", che->num_conta);
        printf("Código Banco: %s\n", che->cod_banco);
        printf("Número Cheque: %d\n", che->num_cheque);
        printf("Valor do cheque: %f\n", che->valor);
        printf("Data de postagem: %s\n", che->data_cadastro);
        printf("Data de desconto: %s\n", che->data_desconto);
        printf("Id do cheque: %s\n",che->id);

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

        else{
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
            fclose(fp);
        }

        if (!achou)
        {
            printf("\nCheque não encontrado\n");
        }

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
        printf("\nNão existem dados cadastrados no arquivo\n");
    }

    else{
        exibe_cheque(che);
        printf("\nEste é o cheque que você quer atualizar(S/s)? ");
        scanf("%c", &resp);
        getchar();

        if (resp == 'S' || resp == 's')
        {
            printf("____________________________________________________\n");
            printf("                                                    \n");
            printf("             1 - Agência                            \n");
            printf("             2 - CPF                                \n");
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
                    printf("Informe a do cpf: ");
                    scanf(" %[0-9]", che->cpf_cliente);
                    printf("\nCheque editado com sucesso!\n");
                    break;

                case '3':
                    printf("Informe o código do banco: ");
                    scanf(" %[0-9]", che->cod_banco);
                    printf("\nCheque editado com sucesso!\n");
                    break;

                case '4':
                    printf("Informe a data de desconto: ");
                    scanf(" %[0-9]", che->data_desconto);
                    printf("\nCheque editado com sucesso!\n");
                    break;

                case '5':
                    printf("Informe o número da conta: ");
                    scanf(" %[0-9]", che->num_conta);
                    printf("\nCheque editado com sucesso!\n");
                    break;

                case '6':
                    printf("Informe o valor: ");
                    scanf(" %f", &che->valor);
                    printf("\nCheque editado com sucesso!\n");
                    break;

                case '7':
                    printf("\nInforme a agência: ");
                    scanf(" %[0-9]", che->agencia);
                    // printf("\nInforme a o número do cheque: ");
                    // scanf(" %[0-9]", che->num_cheque);
                    printf("\nInforme o código do banco: ");
                    scanf(" %[0-9]", che->cod_banco);
                    printf("\nInforme a data de desconto: ");
                    scanf(" %[0-9]", che->data_desconto);
                    printf("\nInforme o número da conta: ");
                    scanf(" %[0-9]", che->num_conta);
                    printf("\nInforme o valor: ");
                    scanf(" %f", &che->valor);
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
}

int valida_cheque(char* id)
{
    FILE *fp;
    Cheque *che_arq;

    che_arq = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");
    if (fp == NULL)
    {
        return 1;
    }

    while (!feof(fp))
    {
        fread(che_arq, sizeof(Cheque), 1, fp);
        if (strcmp(id, che_arq->id) == 0 && (che_arq->status != 'x'))
        {
            printf("\n\tCheque já cadastrado,\n\tpor favor insira novas informações\n");
            return 0;
        }
    }

    return 1;
}

int def_num(){
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
        return (che_arq->num_cheque + 1);
    }
}

void gera_id(Cheque* che){
    memset(che->id,0,sizeof(che->id)); // Função para limpar a string 
    strcat(che->id,che->agencia);
    strcat(che->id,che->num_conta);
    strcat(che->id,che->cod_banco);
}

int valida_cli(char* cpf){
    FILE* fp;
    Cliente* cli;
    cli = (Cliente*) malloc(sizeof(Cliente));
    fp = fopen("cliente.txt","rt");

    if (fp == NULL){
        free(cli);
        return 0;
    }

    else{
        while(!feof(fp)){
            fread(cli,sizeof(Cliente),1,fp);
            if(strcmp(cli->cpf_cliente,cpf) == 0 && (cli->status != 'x')){
                fclose(fp);
                free(cli);
                return 1;
            }
        }
    }

    fclose(fp);
    free(cli);
    return 0;
}
