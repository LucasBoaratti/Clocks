#define TAM_MAX 50000

typedef struct _pilha {
    int vetor[TAM_MAX];
    int topo;
} Pilha;

void inicializar();
int numeroAleatorio(int low, int high);
int obterDado();
void exibirDado(int p);
int verificarVazia();
int verificarCheia();
void push(int dado);
void imprimir();
int pop();