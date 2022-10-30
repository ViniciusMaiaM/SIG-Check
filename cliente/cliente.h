typedef struct cliente Cliente;

struct cliente {
    char nome_cliente[30];
    char cpf_cliente[15];
    char cel_cliente[19];
    char email_cliente[30];
};


void tela_cliente(void);
void escolha_cliente(char);
void cadastro_cliente(void);
void pesquisar_cliente(void);
void excluir_cliente(void);
void relatorio_cliente(void);