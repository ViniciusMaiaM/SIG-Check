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
  char esc;
  esc = tela_usuario();
  while (esc != '0')
  {
    switch (esc)
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
  return 0;
}

char tela_usuario(void)
{
  // Requisitar login ou criação de conta
  char esc;
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
  esc = input(esc);
  return esc;
}

char cadastrar_check(void)
{
  char esc;
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
  esc = input(esc);
  while (esc != '0')
  {
    switch (esc)
    {
    default:
      printf("Em desenvolvimento!");
      break;
    }
  }
}

char relatorio_check(void)
{
  char esc;
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
  return input(esc);
}