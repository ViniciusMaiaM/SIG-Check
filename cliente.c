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
    char nome[30];
    char cpf[15];
    char celular[19];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("          Nome completo: ");
    scanf("%[A-Z a-z]",nome);
    printf("          CPF: ");
    scanf("%[0-9]",cpf);
    getchar();
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

void pesquisar_cliente(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
    system("clear||cls");
    char nome[30];
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
    printf("          - - - - Pesquisar cliente - - - -         \n");
    printf("                                                    \n");
    printf("           Informe o nome: ");
    scanf("%s",nome);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    printf("Pressione enter para continuar!\n");
    getchar();
}