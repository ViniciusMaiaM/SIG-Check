#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h> //tem que incluir string e math
#include <math.h>
#include "cheque.h"

void muda_tela_cheque(char escolha) //cadastro de cheque
{ 
  switch (escolha)
  {
    case '1':
      cadastrar_cheque();
      break;
      
    case '2':
      pesquisar_cheque();
      break;
      
    case '3': 
      excluir_cheque();
      break;
      
    case '4':
      break;

    default:
      printf("Por favor insira uma opcao valida.\n");
      break;
  }
}

void tela_cheque(void) {
  char escolha;
  system("clear||cls");
  printf("\n");
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("             - - - - Cheque - - - -                 \n");
  printf("                                                    \n");
  printf("             1 - Cadastrar Cheque                   \n");
  printf("             2 - Pesquisar cheque                   \n");
  printf("             3 - Excluir cheque                     \n");
  printf("             4 - Relatorio                          \n");
  printf("             0 - Voltar                             \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  escolha = input();
  muda_tela_cheque(escolha);
} 

void cadastrar_cheque(void) { //Tela que recebe informacoes iniciais do user, precisamos criar validacoes
  char id[16];
  char cpf[15];
  char nome[30];
  int valor;
  char receptor[20];
  system("clear||cls");
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Cadastrar cheque - - - -          \n");
  printf("                                                    \n");
  printf("          ID: ");
  scanf("%[A-Z a-z.,0-9]",id);
  getchar();
  printf("          CPF: ");
  scanf("%[0-9]",cpf);
  getchar();
  printf("          Nome do cliente: ");
  scanf("%[A-Z a-z]",nome);
  getchar();
  printf("          Valor do cheque: ");
  scanf("%d",&valor);
  getchar();
  printf("          Receptor do cheque: ");
  scanf("%[A-Z a-z]",receptor);
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\nPressione enter para continuar!\n");
  getchar();
}


void pesquisar_cheque(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
  system("clear||cls");
  char id[16];
  printf("\n");
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Pesquisar cheque - - - -          \n");
  printf("                                                    \n");
  printf("           Informe o ID (apenas numeros): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}


void excluir_cheque(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
  system("clear||cls");
  char id[16];
  printf("\n");
  printf(" ____________________________________________________ \n");
  printf("                                                    \n");
  printf("    Universidade Federal do Rio Grande do Norte     \n");
  printf("            Centro de Ensino Superior               \n");
  printf("     Departamento de Computacao e Tecnologia        \n");
  printf("         Disciplina DCT1106 -- Programacao          \n");
  printf("                Projeto SIG-Check                   \n");
  printf("____________________________________________________\n");
  printf("                                                    \n");
  printf("          - - - - Excluir cheque - - - -            \n");
  printf("                                                    \n");
  printf("           Informe o ID (apenas numeros): ");
  scanf("%[A-Z a-z.,0-9]",id);
  printf("                                                    \n");
  printf("                                                    \n");
  printf("                                                    \n");
  printf("____________________________________________________\n");
  printf("\n");
  printf("Pressione enter para continuar!\n");
  getchar();
}

char input(void) //função de input
{
  char n;
  printf("Insira sua escolha: ");
  scanf("%c", &n);
  getchar();
  return n; 
}

void relatorio_cheque(){
  
}

/*
int valida_cpf(char cpf[]){
  
  int validador=2;
  while(validador!=0)
{  //com mascara ###.###.###-##
    int cpf_int[11];
    int soma_d1=0, soma_d2=0, calculo_d, tam,d=0,i=0, digitos;
//    printf("Digite seu cpf (###.###.###-##):\n");
 //   scanf("%s", &cpf);
    tam=strlen(cpf);
  
    while(d<=tam){
      if(cpf[d]!='.' && cpf[d]!='-'){
        cpf_int[i] = cpf[d]-48;
        i=i+1;
      }
      d++;
    }
  
//calculo
i=0;
while(i<9){
  soma_d1 = soma_d1 +((cpf_int[i])*(10-i));
  soma_d2 = soma_d2 +((cpf_int[i])*(11-i));
  i++;
}
// primeiro digito
soma_d1 = (soma_d1 *10)%11;
if(soma_d1>9){
  soma_d1=0;
}
// segundo digito
soma_d2 = ((soma_d2 +(soma_d1*2)) *10)%11;
if(soma_d2 >9){
  soma_d2=0;
}
//calculo dos digitos
calculo_d =(soma_d1 * 10)+soma_d2;
// verificar digitos
i=cpf_int[9];
d=cpf_int[10];
//conferindo
digitos = ((i)*10)+(d);
if(calculo_d==digitos){
  validador=0;
}else{
  validador=1;
  }
}
return validador;
}
*/

/*int valida_string(char array[]){
  int tamanho = sizeof(array)/sizeof(array[0]);
  for(int i = 0; i < tamanho;i++){
    if(!((array[i] >= 'A' && array[i] <='Z') || (array[i] >= 'a' && array[i] <='z'))){
      return 0;
    }
  }
  return 1;
}*/

/*
Ainda em desenvolvimento

void tela_alterar_cheque(void) {
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