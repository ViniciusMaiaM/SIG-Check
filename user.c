#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "user.h"

void valida_user(char escolha) //validação/escolha da tela de usuário
{
  while (escolha != '0')
  {

    if (escolha =  '1'){
      cadastrar_check();
      break;
      }

    else if (escolha = '2'){
      relatorio_check();
      break;
      }

    else{
      printf("Por favor insira uma opcao valida.\n");
      break;
    }
  }
}

void tela_usuario(void) //função de tela do usuário
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
  printf("|          - - - - Modulo Usuario - - - -            |\n");
  printf("|                                                    |\n");
  printf("|             1 - Cadastrar cheque                   |\n");
  printf("|             2 - Relatorio de cheques recebidos     |\n");
  printf("|             0 - Voltar                             |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("Escolha a opcao desejada: ");
  escolha = input(escolha);
  valida_user(escolha);
}

void cadastrar_check(void) //função em desenvolvimento
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
  printf("Em desenvolvimento, pressione enter para voltar!\n");
  getchar();
}

void relatorio_check(void) //função em desenvolvimento
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
  printf("Em desenvolvimento, pressione enter para voltar!\n");
  getchar();
}

char input(char n) //função de input
{
  scanf("%c", &n);
  getchar();
  return n;
}
