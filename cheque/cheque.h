typedef struct cheque Cheque;

struct cheque {
    char agencia[40];
    char cheque_num[40];
    char cod_banco[40];
    char data[40];
    char nome_cliente[40];
    char num_conta[40];
    int valor;
    char status;
};


void att_cheque(Cheque* che);
void exibe_cheque(Cheque* che);
void excluir_cheque(Cheque* che);
void grava_cheque(Cheque* che);
void lista_cheque(void);
void muda_tela_cheque(char escolha);
void pesquisar_cheque(void);
void relatorio_cheque(void);
void tela_cheque(void);
Cheque* busca_cheque(void);
Cheque* cadastrar_cheque(void);
