#define TAM_MAX 5

typedef struct _Lista {
    int vetor[TAM_MAX];
    int fim;
} Lista;

void inicializar();
int verificarVazia();
int verificarCheia();
void inserir(int numero, int posicao);
void imprimir();
int remover(int posicao);

//Funcoes para testes automatizados
void testar1_VaziaLista();
void testar2_InserirLista(int quant);
void testar3_RemoverLista();
void testar4_RemoverLista(int quant);
