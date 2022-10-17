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

int valida_float(float dinheiro){


    if (((dinheiro >= '0') && (dinheiro <= '9')) || (dinheiro = '.')){
        return 1;
    }
    
    return 0;
}