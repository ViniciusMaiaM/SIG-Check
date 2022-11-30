typedef struct caixa Caixa;

struct caixa {
    char cpf_cliente[30];
    char id_cheque[30];
    char entrada_saida_caixa;
    float valor_caixa;
    char data_caixa[40];
    int id_transacao_caixa;
    char status;
};

/*
a = acompensar
c = compensado
d = devolvido
*/

void tela_caixa(void);
void escolha_caixa(char);
void grava_caixa(Caixa* cai);
void ler_cpf(char* cpf);
void pesquisar_caixa(void);
void exibe_caixa(Caixa* cai);
void excluir_caixa(Caixa* cai);
void att_caixa(Caixa* cai);
void lista_caixa(void);

int id_tra();

Caixa* cadastrar_caixa(void);
Caixa* busca_caixa(void);




