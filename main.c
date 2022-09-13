#include <stdio.h>
#include <stdlib.h>
#include "cheque.h"
#include "movimentacao.h"

/////
// Assinatura das funções
/////
char tela_principal(void);
void tela_sobre(void);
void sleep();
///// 
// Programa principal
/////
int main(void) {
  char modulo = ' ';
  while (modulo != '0') {
    modulo = tela_principal(); 
    switch (modulo) {
      case '1':
        tela_cliente();
        break;

      case '2':
        tela_gerencia();
        break;  
      
      case '4':
        tela_sobre();
        break;
    
      default:
        printf("\nEm desenvolvimento!\n");
        sleep(1);
        break;
    }
  }
  return 0;
}

char tela_principal(void) {
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
  printf("|             - - - - SIG-Check - - - -              |\n");
  printf("|                                                    |\n");
  printf("|             1 - Modulo Cliente                     |\n");
  printf("|             2 - Modulo Movimentação                |\n");
  printf("|             3 - Cadastrar Lucro                    |\n");
  printf("|             4 - Sobre o sistema                    |\n");
  printf("|             0 - Sair                               |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("\n");
  escolha = input();
  return escolha;
}

void tela_sobre(void) { 
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
