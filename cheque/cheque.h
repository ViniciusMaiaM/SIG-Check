typedef struct cheque Cheque;

struct cheque {
    char agencia[10];
    char cheque_num[10];
    char cod_banco[10];
    char data[10];
    char nome_cliente[10];
    char num_conta[10];
    int valor;
    char status;
};


void tela_cheque(void);
Cheque* cadastrar_cheque(void);
Cheque* busca_cheque();
void grava_cheque(Cheque* che);
void muda_tela_cheque(char escolha);
void pesquisar_cheque(void);
void excluir_cheque(void);
void relatorio_cheque();
int valida_cpf(char cpf[]);
//int valida_string(char array[]);