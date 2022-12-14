#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h> //biblioteca de data e hora
#include <ctype.h>
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
        if(cai != NULL){
            grava_caixa(cai);
            free(cai);
        }

        else{
            printf("\nNão foi possivel prosseguir pois você não tem cheques cadastrados para esse cliente.");
            printf("\nPor favor, cadastre novos cheques para então prosseguir sua transação!\n");
            espera();
        }
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
    char status;
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

    verifica_cliente(cai->cpf_cliente);
    
    if(cheque_cpf(cai->cpf_cliente)){

        do{
            printf("\n\tId do cheque: ");
            scanf(" %[0-9]",cai->id_cheque);
            getchar();
        }while (!verifica_cheque(cai->id_cheque, cai->cpf_cliente));

        
        do{
            printf("\n\tEntrada ou saída(E/S): ");
            scanf(" %c",&cai->entrada_saida_caixa);
            cai->entrada_saida_caixa = toupper(cai->entrada_saida_caixa);
        }while (!recebe_entrada(cai->entrada_saida_caixa));

        gera_desconto(cai->cpf_cliente);
        cai->valor_caixa = gera_valor(cai->cpf_cliente,cai->id_cheque);
        printf("\n\tValor do cheque: %.2f",cai->valor_caixa);

        do
        {
            printf("\n\tData (dd/mm/aaaa): ");
            scanf(" %[0-9 / -]", cai->data_caixa);
            getchar();
        } while (!data_str(cai->data_caixa,1));

        if(cai->entrada_saida_caixa == 'S'){
            do{
                printf("Cheque compensado ou retornado(P/R): ");
                scanf(" %c", &status);
                status = toupper(status);
            }while(!(status != 'P' || status != 'R'));

            retirar_cheque(cai->id_cheque, status);
        }
        
        else{
            cai->status = 'A';
        }

        cai->id_transacao_caixa = id_tra();
        printf("\n\tSeu id de transação: %d", cai->id_transacao_caixa);
        printf("                                                    \n");
        printf("                                                    \n");
        printf("                                                    \n");
        printf("____________________________________________________\n");
        espera();
        cai->status = 'C';
        cai->prox = NULL;
        return cai;
    }

    else{
        return NULL;
    }
}

void grava_caixa(Caixa *cai)
{
    FILE *fp;
    fp = fopen("caixa.dat", "ab");

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
    printf("           Informe o id da transação: ");
    scanf(" %d", &id);
    getchar();
    cai = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.dat", "rb");

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
    char situacao[20];
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
        printf("Valor: %.2f\n", cai->valor_caixa);
        printf("Data: %s\n", cai->data_caixa);
        printf("Id do cheque: %s\n", cai->id_cheque);
        printf("Id da transação: %d\n", cai->id_transacao_caixa);
        
        if(cai->entrada_saida_caixa == 'E'){
            strcpy(situacao,"Entrada");
        }

        else{
            strcpy(situacao,"Saída");
        }

        printf("Entrada ou saida: %s\n", situacao);
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
        fp = fopen("caixa.dat", "r+b");
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

    fp = fopen("caixa.dat", "r+b");
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
                    printf("\n\tData (dd/mm/aaaa): ");
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

//--------------------------------
int id_tra()
{
    FILE *fp;
    Caixa *cai_arq;
    cai_arq = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.dat", "rb");

    if (fp == NULL)
    {
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

int cheque_cpf(char* cpf){
    system("clear||cls");
    FILE* fp;
    Cheque* che;
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cheques desse cpf - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.dat", "rb");

    if(fp == NULL){
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
        return 0;
    }

    while(fread(che,sizeof(Cheque),1,fp)){
        if(strcmp(che->cpf_cliente,cpf) == 0 && (che->status == 'C')){
            exibe_cheque(che);
            cont++;
        }
    }

    fclose(fp);
    espera();
    free(che);
    
    if(cont > 0){
        return 1;
    }

    return 0;
}

int verifica_cheque(char* cheque, char* cpf){
    FILE* fp;
    Cheque* che;

    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.dat", "rb");

    if(fp == NULL){
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
        return 0;
    }

    else{
        while(!feof(fp)){
            fread(che,sizeof(Cheque),1,fp);
            if(strcmp(che->cpf_cliente,cpf) == 0 && strcmp(che->id, cheque) == 0 && che->status == 'C'){
                return 1;
            }
        }
        fclose(fp);
    }

    return 0;
}

void gera_desconto(char* cpf){
    int positivo = 0;
    int negativo = 0;
    
    FILE* arq_caixa;
    FILE* arq_cliente;
    Caixa* cai;
    Cliente* cli;

    cai = (Caixa*)malloc(sizeof(Caixa));
    arq_caixa = fopen("caixa.dat","rb");

    arq_cliente = fopen("cliente.dat","r+b");
    cli = (Cliente*)malloc(sizeof(Cliente));


    if(arq_caixa != NULL){
        
        while(fread(cai,sizeof(Caixa),1,arq_caixa)){
            if((cai->status == 'C') && strcmp(cai->cpf_cliente, cpf) == 0){
                positivo++;
            }

            else if((cai->status == 'D') && strcmp(cai->cpf_cliente, cpf) == 0){
                negativo++;
            }

        }
        fclose(arq_caixa);


        if(arq_cliente != NULL){
            while(fread(cli,sizeof(Caixa),1,arq_cliente)){
                if(strcmp(cli->cpf_cliente,cpf) == 0 && (positivo%5) == 0 &&(cli->desconto >= 1)){
                    cli->desconto -= positivo/5;
                }

                else if(strcmp(cli->cpf_cliente,cpf) == 0 && negativo > 0){
                    cli->desconto += negativo;
                }
            }
            fclose(arq_cliente);
        }
        
    }

    free(cai);
    free(cli);
}

float gera_valor(char* cpf, char* id){
    FILE* cli_arq;
    FILE* che_arq;
    
    Cliente* cli;
    Cheque* che;

    cli_arq = fopen("cliente.dat","rb");
    cli = (Cliente*)malloc(sizeof(Cliente));
    
    
    che_arq = fopen("cheque.dat","rb");
    che = (Cheque*)malloc(sizeof(Cheque));


    float desconto = 0;
    float valor = 0;
    float total = 0;

    if(che_arq != NULL){

        while(fread(che,sizeof(Cheque),1,che_arq)){
            if(strcmp(che->cpf_cliente,cpf) == 0 && strcmp(che->id,id) == 0){
                valor = che->valor;
                break;
            }
        }
        
        fclose(che_arq);

        if(che_arq != NULL){
            while(fread(cli,sizeof(Cliente),1,cli_arq)){
                if(strcmp(cli->cpf_cliente,cpf) == 0){
                    desconto = cli->desconto;
                    break;
                }

            }
            fclose(cli_arq);
        }
    }
    
    free(cli);
    free(che);
    total = ((desconto/100) * valor) + valor;
    espera();
    return total;
}

void retirar_cheque(char* id, char status){
    FILE* fp;
    Cheque* che;
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.dat", "r+b");
    while(!feof(fp)){
        fread(che,sizeof(Cheque),1,fp);
        if(strcmp(che->id, id) == 0 && (che->status != 'x')){
            if(status == 'C'){
                che->status = 'P';
            }

            else{
                che->status = 'D';
            }

            fseek(fp,-1*sizeof(Cheque), SEEK_CUR);
            fwrite(che, sizeof(Cheque), 1, fp);
            break;
        }
    }
    free(che);
    fclose(fp);
}

int recebe_entrada(char input){
    if(input == 'E' || input == 'S'){
        return 1;
    }
    return 0;
}
