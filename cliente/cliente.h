typedef struct cliente Cliente;

struct cliente {
    char nome_cliente[30];
    char cpf_cliente[15];
    char cel_cliente[19];
    char email_cliente[30];
    char status;
};


void att_cliente(Cliente* cli);
void escolha_cliente(char);
void excluir_cliente(void);
void exibe_cliente(Cliente* cli);
void grava_cliente(Cliente* cli);
void lista_cliente(void);
void pesquisar_cliente(void);
void tela_cliente(void);
int valida_cliente(Cliente* cli);
Cliente* cadastro_cliente(void);
Cliente* busca_cliente(void);
