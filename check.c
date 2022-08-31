#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "user.h"

char tela_princ(void);
void sobre(void);
char input(char);

char input(char n)
{
  scanf("%c", &n);
  getchar();
  return n;
}

char tela_princ(void)
{
  char esc;
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
  printf("|             - - - - SIG-Check - - - -              |\n");
  printf("|                                                    |\n");
  printf("|             1 - Modulo Usuario                     |\n");
  printf("|             2 - Modulo Gerencia                    |\n");
  printf("|             3 - Modulo Sobre                       |\n");
  printf("|             0 - Sair                               |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("Escolha a opcao desejada: ");
  return input(esc);
}

void sobre(void)
{
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
  printf("|             - - - - SIG-Check - - - -              |\n");
  printf("|                                                    |\n");
  printf("| Projeto tem como objetivo desenvolver um programa  |\n");
  printf("| que realize o cadastro e o acompanhamento de       |\n");
  printf("| cheque pre-datados,auxiliando o controle           |\n");
  printf("| financeiro de uma empresa.                         |\n");
  printf("|____________________________________________________|\n");
  printf("|                                                    |\n");
  printf("|             - - - - Equipe - - - -                 |\n");
  printf("|           - Thamiris Borges(Thami03)               |\n");
  printf("|           - Vinicius Maia(ViniciusMaiaM)           |\n");
  printf("|____________________________________________________|\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}


int main()
{
  char modulo;

  while (modulo != '0')
  {
    modulo = tela_princ();
    switch (modulo)
    {
    case '1':
      tela_usuario();
      break;

    case '2':
      printf("Em desenvolvimento!");
      break;

    case '3':
      sobre();
      break;

    default:
      printf("Por favor insira uma opcao valida.\n");
      sleep(1.2);
      break;
    }
  }

  printf("\nFim do programa!");
  return 0;
}
