typedef struct cheque Cheque;

struct cheque {
    char agencia[40];
    char num_conta[40];
    char cod_banco[40];
    char cpf_cliente[30];
    int valor;
    int num_cheque;
    char data[40];
    char id[40];
    char status;
};


void att_cheque(Cheque* che);
void exibe_cheque(Cheque* che);
void excluir_cheque(Cheque* che);
void grava_cheque(Cheque* che);
void gera_id(Cheque* che);
void muda_tela_cheque(char escolha);
void pesquisar_cheque(void);
void relatorio_cheque(void);
void tela_cheque(void);


int def_num();
int valida_cheque(char* id);

Cheque* busca_cheque(void);
Cheque* cadastrar_cheque(void);
