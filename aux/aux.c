#include <stdio.h>
#include <string.h>
#include "aux.h"

int ddd[27] = {11,21,27,31,41,47,51,61,62,63,65,67,68,69,71,79,81,82,83,84,85,86,91,92,95,96,98};
int meses[] = {31,28,31,30,31,30,31,31,30,31,30,31};


char input(void) //função de input
{
    char n;
    printf("Insira sua escolha: ");
    scanf("%c", &n);
    getchar();
    return n; 
}

int valida_cel(char celular[]){
    
    int tam = strlen(celular);
    int ddd = ((celular[0] - '0') *10) + (celular[1] - '0');

    if (tam != 11){
        return 0;
    }


    if(!busca_ddd(ddd)){
        return 0;
    }

    if(!busca_num(tam,celular)){
        return 0;
    }

    return 1;
}

int busca_ddd(int busca){
    int tam = sizeof(ddd)/sizeof(ddd[0]);
    for(int i = 0; i < tam;i++){
        if (ddd[i] == busca){
            return 1;
        }
    }
    return 0;
}

int busca_num(int tam, char celular[]){
    for(int i = 0; i < tam; i++){
        if(!(celular[i] >= '0' && celular[i] <= '9')){
            return 0;
        }
    }
    return 1;
}


///////////
//Criado com base no algoritmo do professor Flavius Gorgonio
//////////
int data_int(int dia, int mes, int ano){
    int md;
    if (ano < 0 || mes > 12 || mes < 0 || dia < 1){
        return 0;
    }
    
    if  (mes == 2) {
        if (bissexto(ano)){
            md = 29;
        }
        else{
            md = 28;
        }
    }
    
    else if (mes == 4 || mes == 6 || mes == 9 || mes == 11){
        md = meses[mes-1];
    }

    else{
        md = meses[mes-1];
    }

    if (dia > md){
        return 0;
    }

    return 1;
}

///////////
//Criado com base no algoritmo do professor Flavius Gorgonio
//////////
int bissexto (int ano){ 
    if ((ano % 4 == 0) && (ano % 100 != 0)){
        return 1;
    }

    else if (ano % 400 == 0){
        return 1;
    }

    else{
        return 0;
    }
}

int data_str(char data[]){
    int dia, mes, ano;

    if (strlen(data) != 10){
        return 0;
    }

    if (data[2] != '/' || data[5] != '/'){
        return 0;
    }

    dia = ((data[0] - '0') * 10) + (data[1] - '0');
    mes = ((data[3] - '0') * 10) + (data[4] - '0');
    ano = ((data[6] - '0') * 1000) + ((data[7] - '0') * 100) + ((data[8] - '0') * 10) + (data[9] - '0');
    
    if(data_int(dia,mes,ano)){
        return 1;
    }

    return 0;
}

int valida_email(char email[]){

    int arroba = 0, pont = 0;

    if (strlen(email) > 0){
        for(int i = 0; i < strlen(email); i++){
            
            if(email[i] == '@'){
                arroba ++;
            }

            else if(email[i] == '.'){
                pont++;

            }
        }

        if(arroba == 1 && pont!= 0){
            return 1;
        }

        else{
            return 0;
        }
    }
    return 0;
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

// int valida_float(float dinheiro){


//     if (((dinheiro >= '0') && (dinheiro <= '9')) || (dinheiro = '.')){
//         return 1;
//     }
    
//     return 0;
// }

int valida_dig(char dig[]){
    int tam = strlen(dig);

    for (int i = 0; i < tam; i++){
        if(!(dig[i] >= '0' && dig[i] <='9')){
            return 0;
        }
    }

    return 1;
}