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
void gera_desconto(char* cpf);

int id_tra();
int verifica_cheque(char* cheque, char* cpf);
int cheque_cpf(char* cpf);

float gera_valor(char* cpf, char* id);

Caixa* cadastrar_caixa(void);
Caixa* busca_caixa(void);




