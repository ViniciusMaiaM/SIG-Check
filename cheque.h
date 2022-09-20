struct cheque{
    char id[19];
    char cpf[11];
    char nome[30];
    char celular[19];
};

void tela_cliente(void);
void cadastrar_cheque(void);
char input(void);
void muda_tela_cheque(char escolha);
void pesquisar_cheque(void);
void excluir_cheque(void);

//int valida_string(char array[]);