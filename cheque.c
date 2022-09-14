#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "cheque.h"

void valida_cheque(char escolha) //cadastro de cheque
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
      
    default:
      printf("Por favor insira uma opcao valida.\n");
      break;
  }
}

void tela_cliente(void) {
  char escolha;
  system("clear||cls");
  printf("\n");
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             - - - - cheque - - - -                 \n");
  printf("                                                    \n");
  printf("             1 - Cadastrar cheque                   \n");
  printf("             2 - Pesquisar cheque                   \n");
  printf("             3 - Excluir cheque                     \n");
  printf("             0 - Voltar                             \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  escolha = input();
  valida_user(escolha);
} 

void cadastrar_cheque(void) { //Tela que recebe informacoes iniciais do user, precisamos criar validacoes
  char id[16];
  char cpf[11];
  char nome[30];
  char celular[19];
  system("clear||cls");
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Cadastrar cheque - - - -          \n");
  printf("                                                    \n");
  printf("          ID: ");
  scanf("%[A-Z a-z.,0-9]",id);
  getchar();
  printf("          CPF: ");
  scanf("%[0-9]",cpf);
  getchar();
  printf("          Nome completo: ");
  scanf("%[A-Z a-z]",nome);
  /*while(!valida_string(nome)){
    printf("Nome invalido, por favor insira um nome apenas com letras: ");
    scanf("%[A-Z a-z]",nome);
  }*/
  getchar();
  printf("          Celular (apenas numeros): ");
  scanf("%[0-9]",celular);
  getchar();
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
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Pesquisar cheque - - - -          \n");
  printf("                                                    \n");
  printf("           Informe o ID (apenas numeros): ");
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
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Excluir cheque - - - -            \n");
  printf("                                                    \n");
  printf("           Informe o ID (apenas numeros): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}

char input(void) //função de input
{
  char n;
  printf("Insira sua escolha: ");
  scanf("%c", &n);
  getchar();
  return n; 
}

/*int valida_string(char array[]){
  int tamanho = sizeof(array)/sizeof(array[0]);
  for(int i = 0; i < tamanho;i++){
    if(!((array[i] >= 'A' && array[i] <='Z') || (array[i] >= 'a' && array[i] <='z'))){
      return 0;
    }
  }
  return 1;
}*/

/*
Ainda em desenvolvimento

void tela_alterar_cheque(void) {
  system("clear||cls");
  printf("\n");
  printf(" ____________________________________________________ \n");
  printf("|                                                    |\n");
  printf("|    Universidade Federal do Rio Grande do Norte     |\n");
  printf("|            Centro de Ensino Superior               |\n");
  printf("|     Departamento de Computacao e Tecnologia        |\n");
  printf("|         Disciplina DCT1106 -- Programacao          |\n");
  printf("|                Projeto SIG-Check                   |\n");
  printf("|____________________________________________________|\n");
  printf("|                                                    |\n");
  printf("|          - - - - Alterar usuario - - - -           |\n");
  printf("|                                                    |\n");
  printf("|           Informe o ID (apenas numeros):           |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
    getchar();
}
*/



