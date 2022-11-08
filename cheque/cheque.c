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
  Cheque* che;
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
      break;  
      
    case '3': 
      excluir_cheque();
      break;
      
    case '4':
      lista_cheque();
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

Cheque* cadastrar_cheque(void) { //Tela que recebe informacoes iniciais do user, precisamos criar validacoes
  Cheque* che;
  che = (Cheque*) malloc(sizeof(Cheque));
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Cadastrar cheque - - - -          \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          Nome do cliente: "); //Assim ele vai pegar todas as informações do usuario do arquivo
  scanf(" %50[^\n]",che->nome_cliente);
  getchar();

  do {
    printf("          Número do cheque: ");
    scanf(" %[0-9]",che->cheque_num);
    getchar();
  } while(!valida_dig(che->cheque_num));

  do {
    printf("          Código do banco: ");
    scanf(" %[0-9]",che->cod_banco);
    getchar();
  } while(!valida_dig(che->cod_banco));
  
  do {
    printf("          Número agência: ");
    scanf(" %[0-9]",che->agencia);
    getchar();
  } while(!valida_dig(che->agencia));
  
  do {
    printf("          Número conta: ");
    scanf(" %[0-9]",che->num_conta);
    getchar();
  } while(!valida_dig(che->num_conta));
  
  printf("          Valor do cheque: ");
  scanf("%d",&che->valor);
  getchar();

  do{
    printf("          Data para ser descontado: ");
    scanf(" %[0-9 / -]", che->data);
    getchar();
  }while(!data_str(che->data));
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\nPressione enter para continuar!\n");
  getchar();
  che->status = 'c';
  return che;
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


void grava_cheque(Cheque* che){
    FILE* fp;
    fp = fopen("cheque.txt","at");

    if(fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
        exit(1);
    }

    fwrite(che,sizeof(Cheque),1,fp);
    fclose(fp);
}

Cheque* busca_cheque(){
  FILE* fp;
  Cheque* che;
  char num_conta[10];
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Buscar Cheque - - - -             \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("           Informe o número do cheque: ");
  scanf("%[0-9]",num_conta);
  getchar();
  che = (Cheque*) malloc(sizeof(Cheque));
  fp = fopen("cheque.txt","rt");
  
  if(fp == NULL) {
      printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
      exit(1);
  }  
  while(!feof(fp)){ //Busca até o final do arquivo
      fread(che, sizeof(Cheque),1,fp);
      if(strcmp(che->num_conta,num_conta) == 0 && (che->status != 'x')){ /*Verifica se o código é igual e o status*/
          fclose(fp);
          return che;
      }

  }
  
  fclose(fp);
  return NULL;
}

void exibe_cheque(Cheque* che){
  system("clear||cls");
  char situacao[20];
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Relatório Cheque - - - -          \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  if ((che == NULL) || che->status=='x'){
      printf("\nCheque não encontrado\n");
  }

  else{
    printf("\nAgência: %s\n",che->agencia);
    printf("Número Cheque: %s\n",che->cheque_num);
    printf("Código Banco: %s\n",che->cod_banco);
    printf("Data de postagem: %s\n",che->data);
    printf("Nome do cliente: %s\n",che->nome_cliente);
    printf("Número da conta: %s\n",che->num_conta);
    printf("Valor do cheque: %d\n",che->valor);

    if (che->status == 'c'){
      strcpy(situacao,"Cadastrado");
    }

    else if (che->status == 'p'){
      strcpy(situacao,"Pago");  
    }

    else{
      strcpy(situacao,"Não reconhecido");
    }

    printf("Situação do Cheque: %s",situacao);
  }
  printf("\n____________________________________________________\n");
  printf("\nPressione enter...\n");
  getchar();
}

void lista_cheque(){
  FILE* fp;
  Cheque* che;
  printf("\n\tListagem\n");
  che = (Cheque*) malloc(sizeof(Cheque));
  fp = fopen("cheque.txt","rt");

  if(fp == NULL) {
      printf("Ocorreu um erro na abertura do arquivo, não é possivel continuar o programa");
      exit(1);
  } 

  while(fread(che, sizeof(Cheque), 1, fp)){
      if (che->status != 'x'){
          exibe_cheque(che);
      }
  }

  fclose(fp);
  free(che);
}