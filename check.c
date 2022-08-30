#include <stdio.h>
#include <unistd.h> 
#include <stdlib.h>

char telaprinc(void);
char tela_check(void);
void sobre(void);

char telaprinc(void){
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
  scanf("%c", &esc);
  return esc;
}

void sobre(void){
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
}

char tela_check(void){
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
  scanf("%c", &esc);
  return esc;
}

char check(void){
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
  scanf("%c", &esc);
  return esc;
}
char cadastrar_check(void){
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
  scanf("%c", &esc);
  return esc;
}
char relatorio_check(void){
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
  scanf("%c", &esc);
  return esc;
}
int main()
{ 
  char modulo; 
  char mod_check;


  modulo = telaprinc();
  switch (modulo){
  case '1':
    sobre();
    break;
    
  case '2':
	check();
	break;
	
  case '0':
    printf("Fim do programa!\n");
    break;
  
  default:
    printf("Por favor insira uma opcao valida.\n");
  }
  
  mod_check = tela_check();
  switch (mod_check){
	case '1':
    cadastrar_check();
    break;
    
  case '2':
	relatorio_check();
	break;
	
  case '0':
    telaprinc();
    break;

    default:
	  printf("Por favor insira uma opcao valida.\n");
 }
  
}
