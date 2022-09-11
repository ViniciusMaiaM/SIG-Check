#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "cheque.h"

void valida_user(char escolha) //validação/escolha da tela de usuário
{ 
  switch (escolha)
  {

    case '1':
      cadastrar_usuario();
      break;
      
    case '2':
      pesquisar_usuario();
      break;
      
    case '3': 
      excluir_usuario();
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
  printf("|                                                    |\n");
  printf("|    Universidade Federal do Rio Grande do Norte     |\n");
  printf("|            Centro de Ensino Superior               |\n");
  printf("|     Departamento de Computacao e Tecnologia        |\n");
  printf("|         Disciplina DCT1106 -- Programacao          |\n");
  printf("|                Projeto SIG-Check                   |\n");
  printf("|____________________________________________________|\n");
  printf("|                                                    |\n");
  printf("|             - - - - Usuario - - - -                |\n");
  printf("|                                                    |\n");
  printf("|             1 - Cadastrar usuario                  |\n");
  printf("|             2 - Pesquisar usuario                  |\n");
  printf("|             3 - Excluir usuario                    |\n");
  printf("|             0 - Voltar                             |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("\n");
  escolha = input();
  valida_user(escolha);
} 

void cadastrar_usuario(void) {
  char id[16];
  char cpf[16];
  char nome[30];
  char celular[19];
  system("clear||cls");
  printf(" ____________________________________________________ \n");
  printf("|                                                    |\n");
  printf("|    Universidade Federal do Rio Grande do Norte     |\n");
  printf("|            Centro de Ensino Superior               |\n");
  printf("|     Departamento de Computacao e Tecnologia        |\n");
  printf("|         Disciplina DCT1106 -- Programacao          |\n");
  printf("|                Projeto SIG-Check                   |\n");
  printf("|____________________________________________________|\n");
  printf("|                                                    |\n");
  printf("|          - - - - Cadastrar usuario - - - -         |\n");
  printf("|                                                    |\n");
  printf("|          ID: ");
  scanf("%[A-Z a-z.,0-9]",id);
  getchar();
  printf("|          CPF: ");
  scanf("%[0-9]",cpf);
  getchar();
  printf("|          Nome completo: ");
  scanf("%[A-Z a-z]",nome);
  getchar();
  printf("|          Celular (apenas numeros): ");
  scanf("%[0-9]",celular);
  getchar();
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("\nPressione enter para continuar!\n");
  getchar();
}


void pesquisar_usuario(void) {
  system("clear||cls");
  char id[16];
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
  printf("|          - - - - Pesquisar usuario - - - -         |\n");
  printf("|                                                    |\n");
  printf("|           Informe o ID (apenas numeros): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}


void excluir_usuario(void) {
  system("clear||cls");
  char id[16];
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
  printf("|          - - - - Excluir usuario - - - -           |\n");
  printf("|                                                    |\n");
  printf("|           Informe o ID (apenas numeros): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
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

/*
Ainda em desenvolvimento

void tela_alterar_usuario(void) {
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


