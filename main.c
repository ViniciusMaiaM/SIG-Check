#include <stdio.h>
#include <stdlib.h>
#include "aux/aux.h"
#include "caixa/caixa.h"
#include "cheque/cheque.h"
#include "cliente/cliente.h"
#include "main.h"
#include "relatorio/relatorio.h"

/////
// Programa principal
/////
int main(void) {
  char modulo = ' ';
  do {

    modulo = tela_principal();
    switch (modulo) {
    case '1':
      tela_cliente();
      break;

    case '2':
      tela_cheque();
      break;

    case '3':
      tela_caixa();
      break;

    case '4':
      tela_relatorio();
      break;

    case '5':
      tela_sobre();
      break;  
      
    case '0':
      printf("\nAte a proxima!\n");
      break;

    default:
      printf("\nMódulo inexistente!\n");
      espera();
      break;
    }
  } while (modulo != '0');

  return 0;
}

char tela_principal(void) {
  char escolha;
  system("clear||cls");
  printf("\n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             - - - - SIG-Check - - - -              \n");
  printf("                                                    \n");
  printf("             1 - Modulo Cliente                     \n");
  printf("             2 - Modulo Cheque                      \n");
  printf("             3 - Modulo Caixa                       \n");
  printf("             4 - Relatorio                          \n");
  printf("             5 - Sobre o sistema                    \n");
  printf("             0 - Sair                               \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  escolha = input();
  return escolha;
}

void tela_sobre(void) {
  system("clear||cls");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             - - - - SIG-Check - - - -              \n");
  printf("                                                    \n");
  printf(" Projeto tem como objetivo desenvolver um programa  \n");
  printf(" que realize o cadastro e o acompanhamento de       \n");
  printf(" cheque pré-datados, auxiliando o controle          \n");
  printf(" financeiro de uma empresa.                         \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             - - - - Equipe - - - -                 \n");
  printf("           - Thamiris Borges(Thami03)               \n");
  printf("           - Vinícius Maia(ViniciusMaiaM)           \n");
  printf("____________________________________________________\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}
