#include <stdio.h>

char telaprinc();
void sobre();

char telaprinc(){
  char esc;
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
  printf("|             0 - Sair                               |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf(" Escolha a opcao desejada: ");
  scanf("%c", &esc);
  printf(" ____________________________________________________ \n");
  return esc;
}

void sobre()
{
  printf(" ________________________________ \n");
  printf("|            Dupla               |\n");
  printf("| - Thamiris Borges(Thami03)     |\n");
  printf("| - Vinicius Maia(ViniciusMaiaM) |\n");
  printf("|________________________________|\n");
}

int main()
{
  char modulo;

  modulo = telaprinc();
  switch (modulo)
  {
  case '1':
    sobre();
    break;

  case '0':
    printf("\n Fim do programa!\n");
    break;
  }
}