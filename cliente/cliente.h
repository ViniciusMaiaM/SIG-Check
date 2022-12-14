typedef struct cliente Cliente;

struct cliente {
    char nome_cliente[100];
    char cpf_cliente[30];
    char cel_cliente[30];
    char email_cliente[100];
    char data_nasc[15];
    char genero;
    char status;
    int desconto;
    Cliente* prox;
};


void att_cliente(Cliente* cli);
void escolha_cliente(char);
void excluir_cliente(Cliente* cli);
void exibe_cliente(Cliente* cli);
void grava_cliente(Cliente* cli);
void ler_nome(char* nome);
void ler_cpf(char* cpf);
void ler_cel(char* cel);
void ler_email(char* email);
void ler_nasc(char* data_nasc);
void tela_cliente(void);

char ler_genero(char genero);

Cliente* cadastro_cliente(void);
Cliente* busca_cliente(void);
