#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "user.h"

void valida_user(char escolha) //validação/escolha da tela de usuário
{
  while (escolha != '0')
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
        break;
    }
  }
}

void tela_usuario(void) {
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
  printf("Pressione enter para continuar!\n");
  escolha = input(escolha);
  valida_user(escolha);
} 

void cadastrar_usuario(void) {
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
  printf("|          - - - - Cadastrar usuario - - - -         |\n");
  printf("|                                                    |\n");
  printf("|          ID:                                       |\n");
  printf("|          CPF:                                      |\n");
  printf("|          Nome completo:                            |\n");
  printf("|          Celular (apenas numeros):                 |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|                                                    |\n");
  printf("|____________________________________________________|\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}


void pesquisar_usuario(void) {
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
  printf("|          - - - - Pesquisar usuario - - - -         |\n");
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


void excluir_usuario(void) {
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
  printf("|          - - - - Excluir usuario - - - -           |\n");
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

char input(char n) //função de input
{
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



