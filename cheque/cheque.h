typedef struct cheque Cheque;

struct cheque {
    char agencia[40];
    char num_conta[40];
    char cod_banco[40];
    int valor;
    char data[40];
    int id;
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

int def_id();
int valida_cheque(Cheque* che);

Cheque* busca_cheque(void);
Cheque* cadastrar_cheque(void);
