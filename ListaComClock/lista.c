#include <stdio.h>
#include "lista.h"

Lista l;

void inicializar() {
	l.fim = -1;

	printf("\nLista iniciada.\n");
}

int verificarVazia() {
	if (l.fim == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int verificarCheia() {
	if (l.fim == TAM_MAX - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void inserir(int dado, int posicao) {
    //verificar se a lista nao estah cheia
	if (!verificarCheia()) {
		//verifica se a posicao eh maior que fim
		if (posicao > l.fim) {
			//atualiza fim
			l.fim++;

			//guarda elemento na posicao fim
			l.vetor[l.fim] = dado;

			printf("\nNumero %d adicionado com sucesso!\n", dado);
		}
		//senao
		else {
			//deixar a posicao livre transladando os elementos
			for (int i = l.fim; i >= posicao; i--) {
				l.vetor[i + 1] = l.vetor[i];
			}

			//guarda elemento na posicao desejada
			l.vetor[posicao] = dado;

			//atualiza valor de fim
			l.fim++;

			printf("\nNumero %d adicionado com sucesso, mas na posicao %d\n", dado, posicao);
		}
	}
    //se a lista estiver cheia, avisar usuario
	else {
		printf("\nA lista estah cheia.\n");
	}
}

void imprimir() {
	//verifica se a lista estah vazia
	if (!verificarVazia()) {
		//percorre o vetor do inicio ao fim
		for (int i = 0; i <= l.fim; i++) {
			//imprimindo o elemento por elemento do vetor
			printf("%d \t \n", l.vetor[i]);
		}
	}
    //se a lista estiver vazia, informa o usuario
	else {
		printf("\nA lista estah vazia.\n");
	}
}

int remover(int posicao)  {
    //verifica se a lista nao estah vazia
	if (!verificarVazia()) {
		//verifica se existe elemento valido na posicao desejada
		if (posicao <= l.fim) {
			//define uma variavel auxiliar
			int aux = 0;

			//variavel auxiliar guarda o elemento da posicao
			aux = l.vetor[posicao];

			//transladar os elementos da posicao + 1 ate fim
			for (int i = posicao; i < l.fim; i++) {
				l.vetor[i] = l.vetor[i + 1];
			}

			//atualiza o valor do fim da lista
			l.fim--;

			//retorna o valor removido
			return aux;
		}
		//se nao existe elemento na posicao, informa usuario
		else {
			printf("\nNao ha nenhum elemento na posicao %d.\n", posicao);

			return -1;
		}
	}
	//se a lista estiver vazia, informa o usuario
	else {
		printf("\nA lista estah vazia.\n");
	}
}


//Funcoes para testes automatizados
void emitirResultado(int resultado) {
	if(resultado) 
		printf("\nGREEN: Passou!");
	else printf("\nRED: Nao passou!");
}

void testar1_VaziaLista(){
	printf("\nTeste 1: Este teste irah verificar a lista vazia");
	inicializar();
	if(verificarVazia()) {
		emitirResultado(1);
	} else emitirResultado(0);
}

void testar2_InserirLista(int quant){
	if(quant > 10) {
		printf("\nSo eh possivel testar com lista com ateh 10 elementos");
	} else {
		int i, respostaEsperada, 
		    numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
			posicao[10] = {0, 1, 4, 1, 7, 5, 3, 7, 8, 10}, 
			resultado[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {1, 2, 0, 0, 0, 0, 0, 0, 0, 0},
								 {1, 2, 3, 0, 0, 0, 0, 0, 0, 0},
								 {1, 4, 2, 3, 0, 0, 0, 0, 0, 0},
								 {1, 4, 2, 3, 5, 0, 0, 0, 0, 0},
								 {1, 4, 2, 3, 5, 6, 0, 0, 0, 0},
								 {1, 4, 2, 7, 3, 5, 6, 0, 0, 0},
								 {1, 4, 2, 7, 3, 5, 6, 8, 0, 0},
								 {1, 4, 2, 7, 3, 5, 6, 8, 9, 0},
								 {1, 4, 2, 7, 3, 5, 6, 8, 9, 10}
								};
			
		printf("\nTeste 2: Este teste irah inserir %d elementos na lista", quant);
		if (quant > TAM_MAX)
			printf(", e terah que dizer que a lista estah cheia, inserindo somente os %d primeiros", TAM_MAX);
		
		inicializar();
		for(i = 0; i < quant; i++)
			inserir(numeros[i], posicao[i]);
		if(quant > TAM_MAX)
			respostaEsperada = TAM_MAX-1;
		else respostaEsperada = quant-1;
		
		for(i = 0; i < quant && i < TAM_MAX; i++)
			if(l.vetor[i] != resultado[respostaEsperada][i]) {
				emitirResultado(0);
				return;
			}
		emitirResultado(1);
	}
}

void testar3_RemoverLista(){
	int removido = 0;
	printf("\nTeste 3: Este teste irah tentar remover de uma lista vazia");
	inicializar();
	removido = remover(0);
	if(verificarVazia())
		emitirResultado(1);
	else emitirResultado(0);
}

void testar4_RemoverLista(int quant){
	if(quant > 10) {
		printf("\nSo eh possivel testar com lista com ateh 10 elementos");
	} else {
		int i, respostaEsperada, removido,
		    numeros[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 
			posicao[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, 
			posicaoRemover[10][10] = {
								{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{2, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								{2, 2, 1, 0, 0, 0, 0, 0, 0, 0},
								{4, 2, 0, 1, 0, 0, 0, 0, 0, 0},
								{3, 4, 0, 2, 0, 0, 0, 0, 0, 0},
								{6, 1, 4, 0, 2, 1, 0, 0, 0, 0},
								{5, 2, 5, 2, 0, 2, 1, 0, 0, 0},
								{7, 7, 3, 5, 0, 2, 2, 1, 0, 0},
								{5, 5, 5, 0, 4, 4, 2, 1, 1, 0}
								},
				saida[10][10] = {{1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
								 {2, 1, 0, 0, 0, 0, 0, 0, 0, 0},
								 {3, 1, 2, 0, 0, 0, 0, 0, 0, 0},
								 {3, 4, 2, 1, 0, 0, 0, 0, 0, 0},
								 {5, 3, 1, 4, 2, 0, 0, 0, 0, 0},
								 {4, 6, 1, 5, 2, 3, 0, 0, 0, 0},
								 {7, 2, 6, 1, 5, 4, 3, 0, 0, 0},
								 {6, 3, 8, 4, 1, 7, 5, 2, 0, 0},
								 {8, 9, 4, 7, 1, 5, 6, 3, 2, 0},
								 {6, 7, 8, 1, 9, 10, 4, 3, 5, 2}
								};
		printf("\nTeste 4: Este teste irah inserir %d elemento na lista e remove-lo, deixando a lista vazia", quant);

		inicializar();
		for(i = 0; i < quant; i++)
			inserir(numeros[i], posicao[i]);

		if(quant > TAM_MAX)
			respostaEsperada = TAM_MAX-1;
		else respostaEsperada = quant-1;
		
		for(i = 0; i < quant && i < TAM_MAX; i++) {
			removido = remover(posicaoRemover[respostaEsperada][i]);
			
			if(removido != saida[respostaEsperada][i]) {
				emitirResultado(0);
				return;
			}
		}
		//verifica se a lista ficou vazia
		if(verificarVazia())
			emitirResultado(1);
		else emitirResultado(0);
		}
}

