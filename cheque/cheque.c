#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //tem que incluir string e math
#include <math.h>
#include <time.h> //biblioteca de data e hora
#include "cheque.h"
#include "../aux/aux.h"

void muda_tela_cheque(char escolha) //cadastro de cheque
{ 
  switch (escolha)
  {
    case '1':
      cadastrar_cheque();
      break;
      
    case '2':
      pesquisar_cheque();
      break;
      
    case '3': 
      excluir_cheque();
      break;
      
    case '4':
      relatorio_cheque();
      break;

    default:
      printf("Por favor insira uma opcao valida.\n");
      break;
  }
}

void tela_cheque(void) {
  char escolha;
  system("clear||cls");
  printf("\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             - - - - Cheque - - - -                 \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             1 - Cadastrar Cheque                   \n");
  printf("             2 - Pesquisar cheque                   \n");
  printf("             3 - Excluir cheque                     \n");
  printf("             4 - Relatório                          \n");
  printf("             0 - Voltar                             \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  escolha = input();
  muda_tela_cheque(escolha);
} 

void cadastrar_cheque(void) { //Tela que recebe informacoes iniciais do user, precisamos criar validacoes
  char cheque_num[10];
  char cod_banco[10];
  char nome_cliente[10];
  char agencia[10];
  char num_conta[10];
  int valor;
  char data[10];
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Cadastrar cheque - - - -          \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          Nome do cliente: "); //Assim ele vai pegar todas as informações do usuario do arquivo
  scanf("%50[^\n]",nome_cliente);
  getchar();

  do {
    printf("          Número do cheque: ");
    scanf("%[0-9]",cheque_num);
    getchar();
  } while(!valida_dig(cheque_num));

  do {
    printf("          Código do banco: ");
    scanf("%[0-9]",cod_banco);
    getchar();
  } while(!valida_dig(cod_banco));
  
  do {
    printf("          Número agência: ");
    scanf("%[0-9]",agencia);
    getchar();
  } while(!valida_dig(agencia));
  
  do {
    printf("          Número conta: ");
    scanf("%[0-9]",num_conta);
    getchar();
  } while(!valida_dig(num_conta));
  
  printf("          Valor do cheque: ");
  scanf("%d",&valor);
  getchar();

  do{
    printf("          Data para ser descontado: ");
    scanf("%[0-9 / -]", data);
    getchar();
  }while(!data_str(data));
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\nPressione enter para continuar!\n");
  getchar();
}


void pesquisar_cheque(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
  system("clear||cls");
  char id[16];
  printf("\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Pesquisar cheque - - - -          \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("           Informe o ID (apenas números): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}


void excluir_cheque(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
  system("clear||cls");
  char id[16];
  printf("\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Excluir cheque - - - -            \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("           Informe o ID (apenas números): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}



void relatorio_cheque(){
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Relatório Cheque - - - -          \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          Nome do cliente: Flávius\n");
  printf("          Número do cheque: 000158\n");
  printf("          Número do banco: 001\n");
  printf("          Número agência: 4321\n");
  printf("          Número conta: 468293-1\n");
  printf("          Valor do cheque: 1500.00\n");
  printf("          Receptor do cheque: Vinicius\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          Nome do cliente: Thamirys\n");
  printf("          Número do cheque: 000132\n");
  printf("          Número do banco: 001\n");
  printf("          Número agência: 1234\n");
  printf("          Número conta: 273673-1\n");
  printf("          Valor do cheque: 300.00\n");
  printf("          Receptor do cheque: Italo\n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\nPressione enter para continuar!\n");
  getchar();
}

