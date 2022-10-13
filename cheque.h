/*struct cheque {
    char id[19];
    char cpf[11];
    char nome[30];
    char celular[19];
    int valor;
    char receptor[20];
};
typedef struct cheque Cheque;
void set_cadastro(Cheque c, char id[19], char cpf[11], char nome[30], char celular[19], int valor, char receptor[20]);
void print_struct(cheque *c);*/

void tela_cheque(void);
void cadastrar_cheque(void);
char input(void);
void muda_tela_cheque(char escolha);
void pesquisar_cheque(void);
void excluir_cheque(void);
void relatorio_cheque();
//int valida_string(char array[]);