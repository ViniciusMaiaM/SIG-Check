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
    printf("             1 - Listagem de cadastrados            \n");
    printf("             2 - Listagem por status                \n");
    printf("             3 - Listagem por nascimento            \n");
    printf("             4 - Listagem por ordem alfabetica      \n");
    printf("             5 - Listagem por gênero                \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolhe_cliente(escolha);
}

void relatorio_status(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Status - - - -               \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem dos deletados             \n");
    printf("             2 - Listagem de todos                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    
    if(escolha != '0'){
        lista_status(escolha);
    }

    else{
        printf("\nOk!\n");
    }
}

void escolhe_cliente(char escolha)
{
    switch (escolha)
    {
    case '1':
        lista_cliente();
        break;

    case '2':
        relatorio_status();
        break;

    case '3':
        printf("Por nascimento");
        break;

    case '4':
        lista_alfabetica();
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
    fp = fopen("cliente.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão exitem clientes cadastrados, por favor cadastre para prosseguir.\n");
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
        fclose(fp);
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
    free(cli);
}

void lista_status(char escolha){
    system("clear||cls");
    FILE* fp;
    Cliente *cli;
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        - - - - Listagem por status - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    cli = (Cliente *)malloc(sizeof(Cliente));
    fp = fopen("cliente.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão exitem clientes cadastrados, por favor cadastre para prosseguir.\n");
    }

    else{
        if(escolha == '1'){
            while (fread(cli, sizeof(Cliente), 1, fp))
            {
                if (cli->status == 'x')
                {
                    exibe_cliente(cli);
                    cont++;
                }
            }
        }

        else{
            while (fread(cli, sizeof(Cliente), 1, fp)){
                        exibe_cliente(cli);
                        cont++;
            }
        }

        fclose(fp);
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
    free(cli);
}

void lista_alfabetica(void){
    FILE* fp;
    Cliente* cli;
    Cliente* lista;
    Cliente* novo;

    fp = fopen("cliente.dat","rb");

    if (fp == NULL){
        printf("\nNão é possível continuar a listagem");
    }

    else{
        lista = NULL;
        cli = (Cliente*)malloc(sizeof(Cliente));

        while(fread(cli,sizeof(Cliente),1,fp)){
            if(cli->status != 'x'){
                novo = (Cliente*)malloc(sizeof(Cliente));
                
                strcpy(novo->nome_cliente, cli->nome_cliente);

                strcpy(novo->cpf_cliente, cli->cpf_cliente);

                strcpy(novo->cel_cliente, cli->cel_cliente);

                strcpy(novo->email_cliente, cli->email_cliente);

                strcpy(novo->data_nasc, cli->data_nasc);

                novo->genero = cli->genero;

                novo->status = cli->status;
            }

            if(lista == NULL){
                lista = novo;
                novo->prox = NULL;
            }

            else if(strcmp(novo->nome_cliente, lista->nome_cliente) < 0){
                novo->prox = lista;
                lista = novo;
            }

            else{
                Cliente* anterior = lista;
                Cliente* atual = lista->prox;

                while((atual != NULL) && strcmp(atual->nome_cliente,novo->nome_cliente) < 0){
                    anterior = atual;
                    atual = novo->prox;
                }

                anterior->prox = novo;
                novo->prox = atual;
            }
        }
    }

    free(cli);
    novo = lista;

    while(novo != NULL){
        exibe_cliente(novo);
        espera();
        novo = novo->prox;
    }

    novo = lista;

    while(lista != NULL){
        lista = lista->prox;
        free(novo);
        novo = lista;
    }

    fclose(fp);
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

void relatorio_valor(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Valor - - - -                \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem em ordem crescente        \n");
    printf("             2 - Listagem em ordem decrescente      \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    
    if(escolha != '0'){
        lista_valor(escolha);
    }

    else{
        printf("\nOk!\n");
    }
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
        relatorio_valor();
        break;

    case '4':
        printf("Por data, entre dadas, ultimo espaço de tempo");
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
    fp = fopen("cheque.dat", "rb");

    if (fp == NULL)
    {
        printf("Você não possui cheques cadastrados, por favor cadastre para então poder listar");
    }

    else{
        while (fread(che, sizeof(Cheque), 1, fp)){
            if (che->status != 'x')
            {
                exibe_cheque(che);
                cont++;
            }
        }
        fclose(fp);
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
    fp = fopen("cheque.dat", "rb");

    printf("          Insira o cpf para ser buscado: ");
    scanf(" %[0-9]", cpf);
    getchar();

    if(fp == NULL){
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
    }

    else{
        while(fread(che,sizeof(Cheque),1,fp)){
            if(strcmp(che->cpf_cliente,cpf) == 0 && (che->status != 'x')){
                exibe_cheque(che);
                cont++;
            }
        }
        fclose(fp);
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
    free(che);
}


void lista_valor(char escolha){
    FILE* fp;
    Cheque* che;
    Cheque* lista;
    Cheque* novo;

    fp = fopen("cheque.dat","rb");

    if (fp == NULL){
        printf("\nNão é possível continuar a listagem");
    }

    else{
        lista = NULL;
        che = (Cheque*)malloc(sizeof(Cheque));

        while(fread(che,sizeof(Cheque),1,fp)){
            if(che->status != 'x'){
                novo = (Cheque*)malloc(sizeof(Cheque));
                
                strcpy(novo->agencia, che->agencia);

                strcpy(novo->num_conta, che->num_conta);

                strcpy(novo->cod_banco, che->cod_banco);

                strcpy(novo->cpf_cliente, che->cpf_cliente);

                novo->valor = che->valor;

                novo->num_cheque = che->num_cheque;

                strcpy(novo->data_desconto, che->data_desconto);

                strcpy(novo->data_cadastro, che->data_cadastro);

                strcpy(novo->id, che->id);

                novo->status = che->status;

                novo->status = che->status;
            }

            if(lista == NULL){
                lista = novo;
                novo->prox = NULL;
            }

            if(escolha == '1'){
                if(novo->valor < lista->valor){
                    novo->prox = lista;
                    lista = novo;
                }

                else{
                    Cheque* anterior = lista;
                    Cheque* atual = lista->prox;

                    while((atual != NULL) && atual->valor < novo->valor){
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }

            else if (escolha == '2'){
                if(novo->valor > lista->valor){
                    novo->prox = lista;
                    lista = novo;
                }

                else{
                    Cheque* anterior = lista;
                    Cheque* atual = lista->prox;

                    while((atual != NULL) && atual->valor > novo->valor){
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }
        }
    }

    free(che);
    novo = lista;

    while(novo != NULL){
        exibe_cheque(novo);
        espera();
        novo = novo->prox;
    }

    novo = lista;

    while(lista != NULL){
        lista = lista->prox;
        free(novo);
        novo = lista;
    }

    fclose(fp);
}
