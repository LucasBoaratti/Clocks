#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lista.h"

Lista l;

void inicializar() {
	l.fim = -1;

	printf("\nLista iniciada.\n");
}

// Funcoes para o trabalho de clocks
int numeroAleatorio(int low, int high) {
	int k;
	double d;

	d = (double) rand () / ((double) RAND_MAX + 1);
	
	k = d * (high - low + 1);

	return low + k;
}

int obterDado() {
	return numeroAleatorio(0, TAM_MAX);
}

void exibirDado(int p) {
	printf("\nElemento: %i", p);
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