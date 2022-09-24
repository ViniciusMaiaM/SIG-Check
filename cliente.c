#include <stdio.h>

void escolha_cliente (char escolha) //cadastro de cheque
{ 
    switch (escolha)
    {
        case '1':
        break;
        
        case '2':
        break;
        
        case '3': 
        break;
        
        case '4':
        break;

        default:
        printf("Por favor insira uma opcao valida.\n");
        break;
    }
}


void tela_cliente(void) {
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
    printf("             1 - Cadastrar Cliente                  \n");
    printf("             2 - Pesquisar Cliente                  \n");
    printf("             3 - Excluir   Cliente                  \n");
    printf("             4 - Relatorio Cliente                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    muda_tela_cheque(escolha);
} 

void cadastro_cliente(void){
    char id[16];
    char cpf[15];
    char nome[30];
    char celular[19];
    int valor;
    char receptor[20];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("          ID: ");
    scanf("%[A-Z a-z.,0-9]",id);
    getchar();
    printf("          CPF: ");
    scanf("%[0-9]",cpf);
    getchar();
    printf("          Nome completo: ");
    scanf("%[A-Z a-z]",nome);
    getchar();
    printf("          Celular (apenas numeros): ");
    scanf("%[0-9]",celular);
    getchar();
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
}