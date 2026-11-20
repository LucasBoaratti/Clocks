#define TAM_MAX 50000

typedef struct _Lista {
    int vetor[TAM_MAX];
    int fim;
} Lista;

void inicializar();
int numeroAleatorio(int low, int high);
int obterDado();
void exibirDado(int p);
int verificarVazia();
int verificarCheia();
void inserir(int numero, int posicao);
void imprimir();
int remover(int posicao);