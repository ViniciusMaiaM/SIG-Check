#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h> //biblioteca de data e hora
#include "caixa.h"
#include "../cheque/cheque.h"
#include "../cliente/cliente.h"
#include "../aux/aux.h"

void escolha_caixa(char escolha)
{
    Caixa *cai;
    switch (escolha)
    {
    case '1':
        cai = cadastrar_caixa();
        grava_caixa(cai);
        free(cai);
        break;
    case '2':
        cai = busca_caixa();
        exibe_caixa(cai);
        break;
    case '3':
        cai = busca_caixa();
        excluir_caixa(cai);
        free(cai);
        break;
    case '4':
        cai = busca_caixa();
        att_caixa(cai);
        free(cai);
        break;
    case '5':
        lista_caixa();
        break;

    default:
        break;
    }
}

void tela_caixa(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Caixa - - - -                  \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar transação                \n");
    printf("             2 - Pesquisar transação                \n");
    printf("             3 - Excluir transação                  \n");
    printf("             4 - Atualizar transação                \n");
    printf("             5 - Relatório                          \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolha_caixa(escolha);
}

Caixa *cadastrar_caixa(void)
{
    Caixa *cai;
    cai = (Caixa*)malloc(sizeof(Caixa));
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar caixa - - - -           \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    do
    {
        printf("\n\tCPF: ");
        scanf(" %[0-9]", cai->cpf_cliente);
        getchar();
    } while (!valida_cpf(cai->cpf_cliente));

    if(!valida_cli(cai->cpf_cliente)){
            printf("\nCPF não cadastrado, por favor cadastre o cliente!");
            espera();
            Cliente* cli;
            cli = cadastro_cliente();
            grava_cliente(cli);
            free(cli);
            system("clear||cls");
    }

    printf("\nEsses são os cheques cadastrados para esse cpf");
    cheque_cpf(cai->cpf_cliente);

    do{
        printf("\n\tId do cheque: ");
        scanf(" %[0-9]",cai->id_cheque);
        getchar();
    }while (!verifica_cheque(cai->id_cheque, cai->cpf_cliente));

    printf("\n\tEntrada ou saída(E/S): ");
    scanf("%c",&cai->entrada_saida_caixa);
    getchar();

    printf("\n\tValor do cheque: ");
    scanf("%f", &cai->valor_caixa);
    getchar();

    do
    {
        printf("\n\tData: ");
        scanf(" %[0-9 / -]", cai->data_caixa);
        getchar();
    } while (!data_str(cai->data_caixa,1));


    cai->id_transacao_caixa = id_tra();
    printf("\n\tSeu id de transação: %d", cai->id_transacao_caixa);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    espera();
    cai->status = 'c';
    return cai;
}

void grava_caixa(Caixa *cai)
{
    FILE *fp;
    fp = fopen("caixa.txt", "at");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
    }

    else{
        fwrite(cai, sizeof(Caixa), 1, fp);
        fclose(fp);
    }
}

Caixa *busca_caixa()
{
    FILE *fp;
    Caixa *cai;
    int id;
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Buscar Transação - - - -          \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("           Informe o número da transação: ");
    scanf("%d", &id);
    getchar();
    cai = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.txt", "rt");

    if (fp == NULL)
    {
        printf("Não existe nada cadastrado, por favor cadastre");
    }

    while (!feof(fp))
    { // Busca até o final do arquivo
        fread(cai, sizeof(Caixa), 1, fp);
        if (cai->id_transacao_caixa == id && (cai->status != 'x'))
        { /*Verifica se o código é igual*/
            fclose(fp);
            return cai;
        }
    }

    if(fp!= NULL){
        fclose(fp);
    }

    return NULL;
}

void exibe_caixa(Caixa *cai)
{
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatório Caixa - - - -           \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

    if (cai == NULL)
    {
        printf("\n Transação não encontrada\n");
    }

    else
    {
        printf("CPF: %s\n", cai->cpf_cliente);
        printf("Entrada ou saida: %c\n", cai->entrada_saida_caixa);
        printf("Valor: %.2f\n", cai->valor_caixa);
        printf("\nData: %s\n", cai->data_caixa);
        printf("\nId do check: %s\n", cai->id_cheque);
        printf("\nId da transação: %d\n", cai->id_transacao_caixa);
    }
    printf("\n____________________________________________________\n");
    espera();
}

void excluir_caixa(Caixa *cai)
{
    FILE *fp;
    Caixa *cai_arq;
    int achou = 0;
    char escolha;

    if (cai == NULL)
    {
        printf("\nTransação não encontrada!\n");
    }

    else
    {
        cai_arq = (Caixa *)malloc(sizeof(Caixa));
        fp = fopen("caixa.txt", "r+t");
        if (fp == NULL)
        {
            printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
            exit(1);
        }

        while (!feof(fp))
        {

            fread(cai_arq, sizeof(Caixa), 1, fp);
            if ((strcmp(cai->cpf_cliente, cai->cpf_cliente) == 0))
            {
                exibe_caixa(cai);
                printf("\nEssa é a transação que você quer apagar(S/s)? ");
                scanf(" %c", &escolha);
                achou = 1;

                if (escolha == 'S' || escolha == 's')
                {
                    cai_arq->status = 'x';
                    fseek(fp, -1 * sizeof(Caixa), SEEK_CUR);
                    fwrite(cai_arq, sizeof(Caixa), 1, fp);
                    printf("\nTransação excluída!\n");
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
            printf("\nTransação não encontrada\n");
        }

        fclose(fp);
        free(cai_arq);
    }
    espera();
}

void att_caixa(Caixa *cai)
{
    FILE *fp;
    char resp;
    char escolha;
    char cpf[30];

    if ((cai == NULL) || (cai->status == 'x'))
    {
        printf("\nTransação não encontrada\n");
        exit(1);
    }

    fp = fopen("caixa.txt", "r+t");
    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    exibe_caixa(cai);
    printf("\nEsta é a transação que você quer(S/s)? ");
    scanf("%c", &resp);
    getchar();

    if (resp == 'S' || resp == 's')
    {
        printf("____________________________________________________\n");
        printf("                                                    \n");
        printf("             1 - Atualizar                          \n");
        printf("             0 - Voltar                             \n");
        printf("                                                    \n");
        printf("____________________________________________________\n");
        printf("              você quer atualizar: ");
        scanf("%c", &escolha);
        getchar();

        while (escolha != '0')
        {
            switch (escolha)
            {
            case '1':
                ler_cpf(cpf);
                strcpy(cai->cpf_cliente, cpf);
                printf("Entrada ou saida (E/S):");
                scanf("%c", &cai->entrada_saida_caixa);
                printf("\n\tValor do cheque: ");
                scanf("%f", &cai->valor_caixa);
                do
                {
                    printf("\n\tData: ");
                    scanf(" %[0-9 / -]", cai->data_caixa);
                    getchar();
                } while (!data_str(cai->data_caixa,1));

                printf("\n\tId do cheque: ");
                scanf(" %[0-9]", cai->id_cheque);
                printf("\nTransação editada com sucesso!\n");
                break;

            default:
                printf("\nPor favor insira uma opcao valida.\n");
                break;
            }
            escolha = '0';
        }
        fseek(fp, (-1) * sizeof(Caixa), SEEK_CUR);
        fwrite(cai, sizeof(Caixa), 1, fp);
    }

    else
    {
        printf("\nOk, os dados não foram alterados!\n");
    }
    espera();
    fclose(fp);
}

void lista_caixa(void)
{
    system("clear||cls");
    int cont = 0;
    FILE *fp;
    Caixa *cai;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Listagem - - - -                  \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    cai = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.txt", "rt");

    if (fp == NULL)
    {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    while (fread(cai, sizeof(Caixa), 1, fp))
    {
        if (cai->status != 'x')
        {
            exibe_caixa(cai);
            cont++;
        }
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d transação(s) cadastradas!\n", cont);
    }

    else
    {
        printf("\nVocê não possui transação(s) cadastradas!");
    }

    espera();
    fclose(fp);
    free(cai);
}

//--------------------------------
int id_tra()
{
    FILE *fp;
    Caixa *cai_arq;
    cai_arq = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.txt", "rt");

    if (fp == NULL)
    {
        fclose(fp);
        return 1;
    }

    else
    {
        fseek(fp, -1 * sizeof(Caixa), SEEK_END);
        fread(cai_arq, sizeof(Caixa), 1, fp);
        fclose(fp);
        return (cai_arq->id_transacao_caixa + 1);
    }
}

void cheque_cpf(char* cpf){
    system("clear||cls");
    FILE* fp;
    Cheque* che;
    
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cheques desse cpf - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");

    if(fp == NULL){
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
    }

    else{
        while(!feof(fp)){
            fread(che,sizeof(Cheque),1,fp);
            if(strcmp(che->cpf_cliente,cpf) == 0 && (che->status != 'x')){
                exibe_cheque(che);
            }
        }
        fclose(fp);
    }

    espera();
    free(che);
}

int verifica_cheque(char* cheque, char* cpf){
    FILE* fp;
    Cheque* che;

    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.txt", "rt");

    if(fp == NULL){
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
        return 0;
    }

    else{
        while(!feof(fp)){
            fread(che,sizeof(Cheque),1,fp);
            if(strcmp(che->cpf_cliente,cpf) == 0 && strcmp(che->id, cheque) == 0){
                return 1;
            }
        }
        fclose(fp);
    }

    return 0;
}
