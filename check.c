#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char tela_princ(void);
void tela_check(void);
void sobre(void);
char relatorio_check(void);
char cadastrar_check(void);
char input(char);

char input(char n){
  scanf("%c",&n);
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
  printf("|             1 - Modulo Sobre                       |\n");
  printf("|             2 - Check                              |\n");
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
  printf("Pressione alguma tecla para continuar!\n");
  getchar();
}

void tela_check(void)
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
  printf("|          - - - - Modulo Check - - - -              |\n");
  printf("|                                                    |\n");
  printf("|             1 - Cadastrar cheque                   |\n");
  printf("|             2 - Relatorio de cheques recebidos     |\n");
  printf("|             0 - Voltar                             |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("Escolha a opcao desejada: ");
  esc = input(esc);
  switch (esc)
  {
  case '1':
    cadastrar_check();
    break;

  case '2':
    relatorio_check();
    break;

  case '0':
    tela_princ();
    break;

  default:
    printf("Por favor insira uma opcao valida.\n");
  }
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
  return input(esc);
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
int main()
{
  char modulo;

  do{
    modulo = tela_princ();
    switch (modulo)
    {
    case '1':
      sobre();
      break;

    case '2':
      tela_check();
      break;

    default:
      printf("Por favor insira uma opcao valida.\n");
      break;
    }
  } while (modulo != '0');

  printf("\nFim do programa!");
  return 0;
}
