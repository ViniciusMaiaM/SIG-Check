#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "relatorio.h"
#include "../aux/aux.h"
#include "../cheque/cheque.h"
#include "../cliente/cliente.h"
#include "../caixa/caixa.h"

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
        relatorio_caixa();
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

    if (escolha != '0')
    {
        lista_status(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void relatorio_nascimento(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Nascimento - - - -           \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem em ordem decrescente      \n");
    printf("             2 - Listagem em ordem crescente        \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();

    if (escolha != '0')
    {
        lista_nascimento(escolha);
    }

    else
    {
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
        relatorio_nascimento();
        break;

    case '4':
        lista_alfabetica();
        break;


    case '5':
        lista_genero();
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
            if (cli->status != 'X')
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

void lista_status(char escolha)
{
    system("clear||cls");
    FILE *fp;
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

    else
    {
        if (escolha == '1')
        {
            while (fread(cli, sizeof(Cliente), 1, fp))
            {
                if (cli->status == 'X')
                {
                    exibe_cliente(cli);
                    cont++;
                }
            }
        }

        else
        {
            while (fread(cli, sizeof(Cliente), 1, fp))
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

void lista_alfabetica(void)
{
    FILE *fp;
    Cliente *cli;
    Cliente *lista;
    Cliente *novo;

    fp = fopen("cliente.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão é possível continuar a listagem");
    }

    else
    {
        lista = NULL;
        cli = (Cliente *)malloc(sizeof(Cliente));

        while (fread(cli, sizeof(Cliente), 1, fp))
        {
            if (cli->status != 'X')
            {
                novo = (Cliente *)malloc(sizeof(Cliente));

                strcpy(novo->nome_cliente, cli->nome_cliente);

                strcpy(novo->cpf_cliente, cli->cpf_cliente);

                strcpy(novo->cel_cliente, cli->cel_cliente);

                strcpy(novo->email_cliente, cli->email_cliente);

                strcpy(novo->data_nasc, cli->data_nasc);

                novo->genero = cli->genero;

                novo->status = cli->status;
            }

            if (lista == NULL)
            {
                lista = novo;
                novo->prox = NULL;
            }

            else if (strcmp(novo->nome_cliente, lista->nome_cliente) < 0)
            {
                novo->prox = lista;
                lista = novo;
            }

            else
            {
                Cliente *anterior = lista;
                Cliente *atual = lista->prox;

                while ((atual != NULL) && strcmp(atual->nome_cliente, novo->nome_cliente) < 0)
                {
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

    while (novo != NULL)
    {
        exibe_cliente(novo);
        espera();
        novo = novo->prox;
    }

    novo = lista;

    while (lista != NULL)
    {
        lista = lista->prox;
        free(novo);
        novo = lista;
    }

    fclose(fp);
}

void lista_nascimento(char escolha)
{
    FILE *fp;
    Cliente *cli;
    Cliente *lista;
    Cliente *novo;

    fp = fopen("cliente.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão é possível continuar a listagem");
    }

    else
    {
        lista = NULL;
        cli = (Cliente *)malloc(sizeof(Cliente));

        while (fread(cli, sizeof(Cliente), 1, fp))
        {
            if (cli->status != 'X')
            {
                novo = (Cliente *)malloc(sizeof(Cliente));

                strcpy(novo->nome_cliente, cli->nome_cliente);

                strcpy(novo->cpf_cliente, cli->cpf_cliente);

                strcpy(novo->cel_cliente, cli->cel_cliente);

                strcpy(novo->email_cliente, cli->email_cliente);

                strcpy(novo->data_nasc, cli->data_nasc);

                novo->genero = cli->genero;

                novo->status = cli->status;
            }

            if (lista == NULL)
            {
                lista = novo;
                novo->prox = NULL;
            }

            if (escolha == '1')
            {
                if (nascimento(novo->data_nasc) < nascimento(lista->data_nasc))
                {
                    novo->prox = lista;
                    lista = novo;
                }

                else
                {
                    Cliente *anterior = lista;
                    Cliente *atual = lista->prox;

                    while ((atual != NULL) && nascimento(atual->data_nasc) < nascimento(novo->data_nasc))
                    {
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }

            else if (escolha == '2')
            {
                if (nascimento(novo->data_nasc) > nascimento(lista->data_nasc))
                {
                    novo->prox = lista;
                    lista = novo;
                }

                else
                {
                    Cliente *anterior = lista;
                    Cliente *atual = lista->prox;

                    while ((atual != NULL) && nascimento(atual->data_nasc) > nascimento(novo->data_nasc))
                    {
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }
        }
    }

    free(cli);
    novo = lista;

    while (novo != NULL)
    {
        exibe_cliente(novo);
        espera();
        novo = novo->prox;
    }

    novo = lista;

    while (lista != NULL)
    {
        lista = lista->prox;
        free(novo);
        novo = lista;
    }

    fclose(fp);
}

void lista_genero(void){
    system("clear||cls");
    FILE *fp;
    Cliente *cli;
    int total = 0;
    int masc = 0;
    int fem = 0;
    int out = 0;
    int porc_masc = 0;
    int porc_fem = 0;
    int porc_out = 0;
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
        while (fread(cli, sizeof(Cliente), 1, fp))
        {
            if (cli->status != 'X' && cli->genero == 'M'){
                exibe_cliente(cli);
                total++;
                masc++;
            }

            else if (cli->status != 'X' && cli->genero == 'F'){
                exibe_cliente(cli);
                total++;
                fem++;
            }

            else if (cli->status != 'X' && cli->genero == 'O'){
                exibe_cliente(cli);
                total++;
                out++;
            }
        }
        fclose(fp);

        porc_fem = (100*fem)/total;
        porc_masc = (100*masc)/total;
        porc_out = (100*out)/total;
        printf("\nVocê possui %d cliente(s), dos quais %d são mulheres,",total,fem);
        printf("\n%d são homens e %d são outro",masc,out);

        printf("\nPorcentagem:\nHomens: %d%% \nMulheres: %d%% \nOutros: %d%%",porc_masc,porc_fem,porc_out);
    }


    espera();
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
    printf("             1 - Listagem de cadastrados            \n");
    printf("             2 - Listagem por status                \n");
    printf("             3 - Listagem por cpf                   \n");
    printf("             4 - Listagem por valor                 \n");
    printf("             5 - Listagem por data                  \n");
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

    if (escolha != '0')
    {
        lista_valor(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void relatorio_data(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Data - - - -                 \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Ultimo dia                         \n");
    printf("             2 - Ultimo mês                         \n");
    printf("             3 - Ultimo ano                         \n");
    printf("             4 - Entre datas                        \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();

    if (escolha != '0')
    {
        escolha_data(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void relatorio_entre_data(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Data - - - -                 \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Ordem de cadastro                  \n");
    printf("             2 - Ordem de desconto                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();

    if (escolha != '0')
    {
        entre_data(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void relatorio_status_cheque(){
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Status - - - -               \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem dos pagos                 \n");
    printf("             2 - Listagem dos deletados             \n");
    printf("             3 - Listagem dos retornados            \n");
    printf("             4 - Listagem em acompanhamento         \n");
    printf("             5 - Listagem de todos                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();

    if (escolha != '0')
    {
        lista_cheque_status(escolha);
    }

    else
    {
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
        relatorio_status_cheque();
        break;

    case '3':
        lista_cpf();
        break;

    case '4':
        relatorio_valor();
        break;

    case '5':
        relatorio_data();
        break;

    default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}

void escolha_data(char escolha)
{
    switch (escolha)
    {

    case '1':
        ultima_data(data_atual(),1);
        break;

    case '2':
        ultima_data(data_atual(),2);
        break;

    case '3':
        ultima_data(data_atual(),3);
        break;

    case '4':
        relatorio_entre_data();
        break;

    default:
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

    else
    {
        while (fread(che, sizeof(Cheque), 1, fp))
        {
            if (che->status != 'X')
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

void lista_cpf(void)
{
    system("clear||cls");
    FILE *fp;
    Cheque *che;
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

    if (fp == NULL)
    {
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
    }

    else
    {
        while (fread(che, sizeof(Cheque), 1, fp))
        {
            if (strcmp(che->cpf_cliente, cpf) == 0 && (che->status != 'X'))
            {
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

void lista_valor(char escolha)
{
    FILE *fp;
    Cheque *che;
    Cheque *lista;
    Cheque *novo;

    fp = fopen("cheque.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão é possível continuar a listagem");
    }

    else
    {
        lista = NULL;
        che = (Cheque *)malloc(sizeof(Cheque));

        while (fread(che, sizeof(Cheque), 1, fp))
        {
            if (che->status != 'X')
            {
                novo = (Cheque *)malloc(sizeof(Cheque));

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

            if (lista == NULL)
            {
                lista = novo;
                novo->prox = NULL;
            }

            if (escolha == '1')
            {
                if (novo->valor < lista->valor)
                {
                    novo->prox = lista;
                    lista = novo;
                }

                else
                {
                    Cheque *anterior = lista;
                    Cheque *atual = lista->prox;

                    while ((atual != NULL) && atual->valor < novo->valor)
                    {
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }

            else if (escolha == '2')
            {
                if (novo->valor > lista->valor)
                {
                    novo->prox = lista;
                    lista = novo;
                }

                else
                {
                    Cheque *anterior = lista;
                    Cheque *atual = lista->prox;

                    while ((atual != NULL) && atual->valor > novo->valor)
                    {
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

    while (novo != NULL)
    {
        exibe_cheque(novo);
        espera();
        novo = novo->prox;
    }

    novo = lista;

    while (lista != NULL)
    {
        lista = lista->prox;
        free(novo);
        novo = lista;
    }

    fclose(fp);
}

void entre_data(char escolha)
{
    system("clear||cls");

    FILE *fp;
    Cheque *che;
    char data_inicial[10];
    char data_final[10];

    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("       - - - - Listagem entre datas - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

    fp = fopen("cheque.dat", "rb");
    che = (Cheque *)malloc(sizeof(Cheque));

    if (fp == NULL)
    {
        printf("Não foi possível fazer a listagem");
    }

    do
    {
        printf("\nColoque a data inicial: ");
        scanf(" %[0-9 / -]", data_inicial);
    } while (!(data_str(data_inicial, 0)));

    do
    {
        printf("\nColoque a data final: ");
        scanf(" %[0-9 / -]", data_final);
    } while (!(data_str(data_final, 0)));

    if (escolha == '1')
    {
        while (fread(che, sizeof(Cheque), 1, fp))
        {
            if (compara(data_inicial, data_final, che->data_desconto) && (che->status != 'X'))
            {
                exibe_cheque(che);
                espera();
            }
        }
    }

    else
    {
        while (fread(che, sizeof(Cheque), 1, fp))
        {
            if (compara(data_inicial, data_final, che->data_cadastro) && (che->status != 'X'))
            {
                exibe_cheque(che);
                espera();
            }
        }
    }
    fclose(fp);
    free(che);
}

int compara(char *inicial, char *final, char *arq)
{
    int dia_inicial, mes_inicial, ano_inicial;
    int dia_final, mes_final, ano_final;
    int dia_arq, mes_arq, ano_arq;

    dia_inicial = converte_data(inicial, 1);
    mes_inicial = converte_data(inicial, 2);
    ano_inicial = converte_data(inicial, 3);

    dia_final = converte_data(final, 1);
    mes_final = converte_data(final, 2);
    ano_final = converte_data(final, 3);

    dia_arq = converte_data(arq, 1);
    mes_arq = converte_data(arq, 2);
    ano_arq = converte_data(arq, 3);

    if ((ano_arq <= ano_final) && (ano_arq >= ano_inicial) && (ano_inicial < ano_final))
    {
        if ((ano_arq == ano_final) && (mes_arq == mes_final) && (dia_arq <= dia_final))
        {
            return 1;
        }
        else if ((ano_arq == ano_final) && (mes_arq < mes_final))
        {

            return 1;
        }
        else if ((ano_arq == ano_inicial) && (mes_arq == mes_inicial) && (dia_arq >= dia_inicial))
        {

            return 1;
        }
        else if ((ano_arq == ano_inicial) && (mes_arq > mes_inicial))
        {

            return 1;
        }
        else if (((ano_final - ano_inicial) > 1) && (ano_arq < ano_final) && (ano_arq > ano_inicial))
        {

            return 1;
        }
        else
        {

            return 0;
        }
    }
    else if ((ano_inicial == ano_final) && (ano_arq == ano_inicial))
    {

        if ((mes_inicial == mes_final) && (mes_inicial == mes_arq) && (dia_arq >= dia_inicial) && (dia_arq <= dia_final))
        {

            return 1;
        }
        else if ((mes_arq > mes_inicial) && (mes_arq == mes_final) && (dia_arq <= dia_final))
        {

            return 1;
        }
        else if ((mes_arq < mes_final) && (mes_arq == mes_inicial) && (dia_arq >= dia_inicial))
        {

            return 1;
        }
        else
        {

            return 0;
        }
    }
    else
    {

        return 0;
    }
}


void ultima_data(char* data, int escolha){
    FILE* fp;
    Cheque* che;

    fp = fopen("cheque.dat","rb");

    if(fp == NULL){
        printf("\nNão foi possível abrir o arquivo\n");
    }

    else{
        che = (Cheque*)malloc(sizeof(Cheque));

        while(fread(che,sizeof(Cheque),1,fp)){
            if(escolha == 1){
                if(converte_data(data,1) == converte_data(che->data_cadastro,1)){
                    exibe_cheque(che);
                }
            }

            else if(escolha == 2){
                if(converte_data(data,2) == converte_data(che->data_cadastro,2)){
                    exibe_cheque(che);
                }
            }

            else{
                if(converte_data(data,3) == converte_data(che->data_cadastro,3)){
                    exibe_cheque(che);
                }
            }
        }
        fclose(fp);
    }
    
    free(che);
}

void lista_cheque_status(char escolha){
    system("clear||cls");
    FILE *fp;
    Cheque *che;
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        - - - - Listagem por status - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    che = (Cheque *)malloc(sizeof(Cheque));
    fp = fopen("cheque.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão exitem clientes cadastrados, por favor cadastre para prosseguir.\n");
    }

    else
    {
        if (escolha == '1')
        {
            while (fread(che, sizeof(Cheque), 1, fp))
            {
                if (che->status == 'P')
                {
                    exibe_cheque(che);
                    cont++;
                }

                if (cont > 0)
                {
                printf("\nVocê possui %d cheque(s) pagos!\n", cont);
                }
            }
        }

        else if (escolha == '2')
        {
            while (fread(che, sizeof(Cheque), 1, fp))
            {
                if (che->status == 'X')
                {
                    exibe_cheque(che);
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) deletados!\n", cont);
            }
        }

        else if(escolha == '3')
        {
            while (fread(che, sizeof(Cheque), 1, fp))
            {
                if(che->status == 'R'){
                    exibe_cheque(che);
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) retornados!\n", cont);
            }
        }

        else if(escolha == '4'){
            while (fread(che, sizeof(Cheque), 1, fp))
            {
                if(che->status == 'A'){
                    exibe_cheque(che);
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) em acompanhamento!\n", cont);
            }
        }


        else{
            while (fread(che, sizeof(Cheque), 1, fp))
            {
                exibe_cheque(che);
                cont++;
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) cadastrados!\n", cont);
            }
        }

        fclose(fp);
    }

    

    if(cont == 0)
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }

    espera();
    free(che);
}

void relatorio_caixa(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Caixa - - - -                \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem de cadastrados            \n");
    printf("             2 - Listagem por status                \n");
    printf("             3 - Listagem por cpf                   \n");
    printf("             4 - Listagem por valor                 \n");
    printf("             5 - Listagem por data                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolhe_caixa(escolha);
}

void relatorio_valor_caixa(void)
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

    if (escolha != '0')
    {
        lista_valor_caixa(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void relatorio_data_caixa(void)
{
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Data - - - -                 \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Ultimo dia                         \n");
    printf("             2 - Ultimo mês                         \n");
    printf("             3 - Ultimo ano                         \n");
    printf("             4 - Entre datas                        \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();

    if (escolha != '0')
    {
        escolhe_data_caixa(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void relatorio_status_caixa(){
    char escolha;
    system("clear||cls");
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("               - - - - Status - - - -               \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             1 - Listagem dos pagos                 \n");
    printf("             2 - Listagem dos deletados             \n");
    printf("             3 - Listagem dos retornados            \n");
    printf("             4 - Listagem em acompanhamento         \n");
    printf("             5 - Listagem de todos                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();

    if (escolha != '0')
    {
        lista_caixa_status(escolha);
    }

    else
    {
        printf("\nOk!\n");
    }
}

void escolhe_caixa(char escolha)
{
    switch (escolha)
    {
    case '1':
        lista_caixa();
        break;

    case '2':
        relatorio_status_caixa();
        break;

    case '3':
        lista_cpf_caixa();
        break;

    case '4':
        relatorio_valor_caixa();
        break;

    case '5':
        relatorio_data_caixa();
        break;

    default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}

void escolhe_data_caixa(char escolha)
{
    switch (escolha)
    {

    case '1':
        ultima_data_caixa(data_atual(),1);
        break;

    case '2':
        ultima_data_caixa(data_atual(),2);
        break;

    case '3':
        ultima_data_caixa(data_atual(),3);
        break;

    case '4':
        entre_data_caixa();
        break;

    default:
        break;
    }
}

void lista_caixa(void)
{
    system("clear||cls");
    FILE *fp;
    Caixa *cai;
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Listagem - - - -                  \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    cai = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.dat", "rb");

    if (fp == NULL)
    {
        printf("Você não possui caixa cadastrado, por favor cadastre para então poder listar");
    }

    else
    {
        while (fread(cai, sizeof(Caixa), 1, fp))
        {
            if (cai->status != 'X')
            {
                exibe_caixa(cai);
                cont++;
            }
        }
        fclose(fp);
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d  movimentação(ões) em caixa cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui movimentação cadastrada!");
    }

    espera();
    free(cai);
}

void lista_cpf_caixa(void)
{
    system("clear||cls");
    FILE *fp;
    Caixa *cai;
    char cpf[30];
    int cont = 0;

    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Listagem por cpf - - - -          \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

    cai = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.dat", "rb");

    printf("          Insira o cpf para ser buscado: ");
    scanf(" %[0-9]", cpf);
    getchar();

    if (fp == NULL)
    {
        printf("\nArquivo sem cadastro, não foi possível fazer a listagem\n");
    }

    else
    {
        while (fread(cai, sizeof(Caixa), 1, fp))
        {
            if (strcmp(cai->cpf_cliente, cpf) == 0 && (cai->status != 'X'))
            {
                exibe_caixa(cai);
                cont++;
            }
        }
        fclose(fp);
    }

    if (cont > 0)
    {
        printf("\nVocê possúi %d  movimentação(ões) em caixa cadastrados!\n", cont);
    }

    else
    {
        printf("\nVocê não possui movimentação cadastrada!");
    }

    espera();
    free(cai);
}

void lista_valor_caixa(char escolha)
{
    FILE *fp;
    Caixa *cai;
    Caixa *lista;
    Caixa *novo;

    fp = fopen("caixa.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão é possível continuar a listagem");
    }

    else
    {
        lista = NULL;
        cai = (Caixa *)malloc(sizeof(Caixa));

        while (fread(cai, sizeof(Caixa), 1, fp))
        {
            if (cai->status != 'X')
            {
                novo = (Caixa *)malloc(sizeof(Caixa));

                strcpy(novo->cpf_cliente, cai->cpf_cliente);

                strcpy(novo->id_cheque, cai->id_cheque);

                strcpy(novo->data_caixa, cai->data_caixa);

                novo->entrada_saida_caixa = cai->entrada_saida_caixa;

                novo->valor_caixa = cai->valor_caixa;

                novo->id_transacao_caixa = cai->id_transacao_caixa;

                novo->status = cai->status;
            }

            if (lista == NULL)
            {
                lista = novo;
                novo->prox = NULL;
            }

            if (escolha == '1')
            {
                if (novo->valor_caixa < lista->valor_caixa)
                {
                    novo->prox = lista;
                    lista = novo;
                }

                else
                {
                    Caixa *anterior = lista;
                    Caixa *atual = lista->prox;

                    while ((atual != NULL) && atual->valor_caixa < novo->valor_caixa)
                    {
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }

            else if (escolha == '2')
            {
                if (novo->valor_caixa > lista->valor_caixa)
                {
                    novo->prox = lista;
                    lista = novo;
                }

                else
                {
                    Caixa *anterior = lista;
                    Caixa *atual = lista->prox;

                    while ((atual != NULL) && atual->valor_caixa > novo->valor_caixa)
                    {
                        anterior = atual;
                        atual = novo->prox;
                    }

                    anterior->prox = novo;
                    novo->prox = atual;
                }
            }
        }
    }

    free(cai);
    novo = lista;

    while (novo != NULL)
    {
        exibe_caixa(novo);
        espera();
        novo = novo->prox;
    }

    novo = lista;

    while (lista != NULL)
    {
        lista = lista->prox;
        free(novo);
        novo = lista;
    }

    fclose(fp);
}

void entre_data_caixa(void)
{
    system("clear||cls");

    FILE *fp;
    Caixa *cai;
    char data_inicial[10];
    char data_final[10];

    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("       - - - - Listagem entre datas - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");

    fp = fopen("caixa.dat", "rb");
    cai = (Caixa *)malloc(sizeof(Caixa));

    if (fp == NULL)
    {
        printf("Não foi possível fazer a listagem");
    }

    do
    {
        printf("\nColoque a data inicial: ");
        scanf(" %[0-9 / -]", data_inicial);
    } while (!(data_str(data_inicial, 0)));

    do
    {
        printf("\nColoque a data final: ");
        scanf(" %[0-9 / -]", data_final);
    } while (!(data_str(data_final, 0)));


    while (fread(cai, sizeof(Caixa), 1, fp))
    {
        if (compara(data_inicial, data_final, cai->data_caixa) && (cai->status != 'X'))
        {
            exibe_caixa(cai);
            espera();
        }
    }

    fclose(fp);
    free(cai);
}

void ultima_data_caixa(char* data, int escolha){
    FILE* fp;
    Caixa* cai;

    fp = fopen("caixa.dat","rb");

    if(fp == NULL){
        printf("\nNão foi possível abrir o arquivo\n");
    }

    else{
        cai = (Caixa*)malloc(sizeof(Caixa));

        while(fread(cai,sizeof(Caixa),1,fp)){
            if(escolha == 1){
                if(converte_data(data,1) == converte_data(cai->data_caixa,1)){
                    exibe_caixa(cai);
                }
            }

            else if(escolha == 2){
                if(converte_data(data,2) == converte_data(cai->data_caixa,2)){
                    exibe_caixa(cai);
                }
            }

            else{
                if(converte_data(data,3) == converte_data(cai->data_caixa,3)){
                    exibe_caixa(cai);
                }
            }
        }
        fclose(fp);
    }
    
    free(cai);
}

void lista_caixa_status(char escolha){
    system("clear||cls");
    FILE *fp;
    Caixa *cai;
    int cont = 0;
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("        - - - - Listagem por status - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    cai = (Caixa *)malloc(sizeof(Caixa));
    fp = fopen("caixa.dat", "rb");

    if (fp == NULL)
    {
        printf("\nNão exitem clientes cadastrados, por favor cadastre para prosseguir.\n");
    }

    else
    {
        if (escolha == '1')
        {
            while (fread(cai, sizeof(Caixa), 1, fp))
            {
                if (cai->status == 'P')
                {
                    exibe_caixa(cai);
                    cont++;
                }

                if (cont > 0)
                {
                printf("\nVocê possui %d cheque(s) pagos!\n", cont);
                }
            }
        }

        else if (escolha == '2')
        {
            while (fread(cai,sizeof(Caixa),1,fp))
            {
                if (cai->status == 'X')
                {
                    exibe_caixa(cai);
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) deletados!\n", cont);
            }
        }

        else if(escolha == '3')
        {
            while (fread(cai,sizeof(Caixa),1,fp))
            {
                if(cai->status == 'R'){
                    exibe_caixa(cai);
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) retornados!\n", cont);
            }
        }

        else if(escolha == '4'){
            while (fread(cai,sizeof(Caixa),1,fp))
            {
                if(cai->status == 'A'){
                    exibe_caixa(cai);
                    cont++;
                }
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) em acompanhamento!\n", cont);
            }
        }


        else{
            while (fread(cai,sizeof(Caixa),1,fp))
            {
                exibe_caixa(cai);
                cont++;
            }

            if (cont > 0)
            {
                printf("\nVocê possui %d cheque(s) cadastrados!\n", cont);
            }
        }

        fclose(fp);
    }

    

    if(cont == 0)
    {
        printf("\nVocê não possui cliente(s) cadastrados!");
    }

    espera();
    free(cai);
}
