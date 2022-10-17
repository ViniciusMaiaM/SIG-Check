#include <stdio.h>
#include <stdlib.h>
#include "cliente.h"
#include "../aux/aux.h"
#include <string.h>
#include <math.h>

int valida_cpf(char cpf[]);

void escolha_cliente (char escolha) //cadastro de cheque
{ 
    switch (escolha)
    {
        case '1':
        cadastro_cliente();
        break;
        
        case '2':
        pesquisar_cliente();
        break;
        
        case '3': 
        excluir_cliente();
        break;
        
        case '4':
        relatorio_cliente();
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
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("             - - - - Cliente - - - -                \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("             1 - Cadastrar Cliente                  \n");
    printf("             2 - Pesquisar Cliente                  \n");
    printf("             3 - Excluir   Cliente                  \n");
    printf("             4 - Relatório Cliente                  \n");
    printf("             0 - Voltar                             \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\n");
    escolha = input();
    escolha_cliente(escolha);
} 


void cadastro_cliente(void){
    char nome[30];
    char cpf[15];
    char celular[19];
    char email[30];
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Cadastrar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("          Nome completo: ");
    scanf("%[A-Z a-z]",nome);
    getchar();
    
    do{
        printf("          CPF: ");
        scanf("%s",cpf);
        getchar();
    }while(!valida_cpf(cpf));

    do{
        printf("          Celular (apenas números | Insira DDD): ");
        scanf("%[0-9]",celular);
        getchar();
    }while(!valida_cel(celular));
    
    do{
        printf("          Email: ");
        fgets(email,30,stdin);
    }while(!valida_email(email));
    
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
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Pesquisar cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("           Informe o nome: ");
    scanf("%s",nome);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
}

void excluir_cliente(void) { //Implementar ferramenta de busca quando salvarmos em arquivos
    system("clear||cls");
    char nome[30];
    printf("\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Excluir cliente - - - -           \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("           Informe o nome: ");
    scanf("%s",nome);
    printf("                                                    \n");
    printf("                                                    \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nCliente %s excluido com sucesso!",nome);
    printf("\nPressione enter para continuar!\n");
    getchar();
}

void relatorio_cliente(){
    system("clear||cls");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          - - - - Relatório cliente - - - -         \n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Nome: Vinicius\n");
    printf("          CPF: 123.456.789-10\n");
    printf("          Celular: 912345678\n");
    printf("          Email: vinicius.maia.123@ufrn.edu.br\n");
    printf("____________________________________________________\n");
    printf("                                                    \n");
    printf("          Nome: Thamiris\n");
    printf("          CPF: 123.456.789-10\n");
    printf("          Celular: 912345678\n");
    printf("          Email: thamiris.123@ufrn.edu.br\n");
    printf("                                                    \n");
    printf("____________________________________________________\n");
    printf("\nPressione enter para continuar!\n");
    getchar();
}

// Função para validar cpf


int valida_cpf(char *cpf){
    int validador = 1;
    int cpf_int[11];
    int soma_d1=0, soma_d2=0, calculo_d, tam,d=0,i=0, digitos;
    tam=strlen(cpf);

    while(d<=tam){
        if(cpf[d]!='.' && cpf[d]!='-'){
            cpf_int[i] = cpf[d]-48;
            i=i+1;
        }
        d++;
    }

//Testando cpf com todos os numeros iguais, são considerados válidos pelo calculo, mas são invalidos.
if(cpf_int[0]==0 && cpf_int[1]==0 && cpf_int[2]==0 && cpf_int[3]==0 && cpf_int[4]==0 && cpf_int[5]==0 && cpf_int[6]==0 && cpf_int[7]==0 && cpf_int[8]==0 && cpf_int[9]==0 && cpf_int[10]==0){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}  
else if(cpf_int[0]==1 && cpf_int[1]==1 && cpf_int[2]==1 && cpf_int[3]==1 && cpf_int[4]==1 && cpf_int[5]==1 && cpf_int[6]==1 && cpf_int[7]==1 && cpf_int[8]==1 && cpf_int[9]==1 && cpf_int[10]==1){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}
else if(cpf_int[0]==2 && cpf_int[1]==2 && cpf_int[2]==2 && cpf_int[3]==2 && cpf_int[4]==2 && cpf_int[5]==2 && cpf_int[6]==2 && cpf_int[7]==2 && cpf_int[8]==2 && cpf_int[9]==2 && cpf_int[10]==2){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}
else if(cpf_int[0]==3 && cpf_int[1]==3 && cpf_int[2]==3 && cpf_int[3]==3 && cpf_int[4]==3 && cpf_int[5]==3 && cpf_int[6]==3 && cpf_int[7]==3 && cpf_int[8]==3 && cpf_int[9]==3 && cpf_int[10]==3){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}   
else if(cpf_int[0]==4 && cpf_int[1]==4 && cpf_int[2]==4 && cpf_int[3]==4 && cpf_int[4]==4 && cpf_int[5]==4 && cpf_int[6]==4 && cpf_int[7]==4 && cpf_int[8]==4 && cpf_int[9]==4 && cpf_int[10]==4){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}

else if(cpf_int[0]==5 && cpf_int[1]==5 && cpf_int[2]==5 && cpf_int[3]==5 && cpf_int[4]==5 && cpf_int[5]==5 && cpf_int[6]==5 && cpf_int[7]==5 && cpf_int[8]==5 && cpf_int[9]==5 && cpf_int[10]==5){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}
else if(cpf_int[0]==6 && cpf_int[1]==6 && cpf_int[2]==6 && cpf_int[3]==6 && cpf_int[4]==6 && cpf_int[5]==6 && cpf_int[6]==6 && cpf_int[7]==6 && cpf_int[8]==6 && cpf_int[9]==6 && cpf_int[10]==6){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}
else if(cpf_int[0]==7 && cpf_int[1]==7 && cpf_int[2]==7 && cpf_int[3]==7 && cpf_int[4]==7 && cpf_int[5]==7 && cpf_int[6]==7 && cpf_int[7]==7 && cpf_int[8]==7 && cpf_int[9]==7 && cpf_int[10]==7){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}
else if(cpf_int[0]==8 && cpf_int[1]==8 && cpf_int[2]==8 && cpf_int[3]==8 && cpf_int[4]==8 && cpf_int[5]==8 && cpf_int[6]==8 && cpf_int[7]==8 && cpf_int[8]==8 && cpf_int[9]==8 && cpf_int[10]==8){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}
else if(cpf_int[0]==9 && cpf_int[1]==9 && cpf_int[2]==9 && cpf_int[3]==9 && cpf_int[4]==9 && cpf_int[5]==9 && cpf_int[6]==9 && cpf_int[7]==9 && cpf_int[8]==9 && cpf_int[9]==9 && cpf_int[10]==9){
    printf("CPF inválido, Digite novamente: \n");
    validador=1; 
}

else{
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
        validador=1;
    }else{
        validador=0;
    }
    }
return validador;
}