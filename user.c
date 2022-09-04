#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "user.h"

char tela_usuario(void);
char tela_usuario(void);
char cadastrar_check();
char relatorio_check();

void valida_user()
{
  char escolha;
  escolha = tela_usuario();
  while (escolha != '0')
  {
    switch (escolha)
    {
    case '1':
      cadastrar_check();
      break;

    case '2':
      relatorio_check();
      break;

    default:
      printf("Por favor insira uma opcao valida.\n");
    }
  }
}

char tela_usuario(void)
{
  // Requisitar login ou criação de conta
  char escolha;
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
  printf("|          - - - - Modulo Usuario - - - -            |\n");
  printf("|                                                    |\n");
  printf("|             1 - Cadastrar cheque                   |\n");
  printf("|             2 - Relatorio de cheques recebidos     |\n");
  printf("|             0 - Voltar                             |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("Escolha a opcao desejada: ");
  escolha = input(escolha);
  return escolha;
}

char cadastrar_check(void)
{
  char escolha;
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
  printf("|          - - - - Cadastro de  Cheque - - - -       |\n");
  printf("|                                                    |\n");
  printf("|             1 - A Vista                            |\n");
  printf("|             2 - A Prazo                            |\n");
  printf("|             0 - Voltar                             |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("Escolha a opcao desejada: ");
  escolha = input(escolha);
  while (escolha != '0'){
    switch (escolha){
    default:
      printf("Em desenvolvimento!");
      break;
    }
  }
}

char relatorio_check(void)
{
  char escolha;
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
  printf("|          - - - - Relatorio de Cheque - - - -       |\n");
  printf("|                                                    |\n");
  printf("|             0 - Voltar                             |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("Escolha a opcao desejada: ");
  escolha = input(escolha);
  return escolha;
}

char input(char n)
{
  scanf("%c", &n);
  getchar();
  return n;
}
