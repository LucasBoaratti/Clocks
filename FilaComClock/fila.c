#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fila.h"

Fila f;

void inicializar(){
	//atribui -1 ao membro final da fila
	f.fim = -1;

	printf("\nFila iniciada.\n");
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

int verificarVazia(){
	//verifica se o membro final da fila eh igual a -1
	if (f.fim == -1) {
		return 1;
	}
	else {
		return 0;
	}
}

int verificarCheia() {
	//verifica se o membro final da fila eh igual a TAM_MAX-1
	if (f.fim == TAM_MAX - 1) {
		return 1;
	}
	else {
		return 0;
	}
}

void inserir(int numero){
	//verificar se a fila nao estah cheia
	if (!verificarCheia()) {
		//atualiza o fim da fila
		f.fim++;

		//insere o numero no vetor no final
		f.vetor[f.fim] = numero;
	}
 	//se estiver cheia, informa o usu�rio
	else {
		printf("\nA fila estah cheia.\n");
	}
}

void imprimir(){
	//verificar se a fila n�o est� vazia
	if (!verificarVazia()) {
		//define uma vari�vel auxiliar
		int i;

		//percorre o vetor do in�cio ate o fim da fila
		for (i = f.fim; i >= 0; i--) {
			//imprimir na tela o elemento na posi��o i
			printf("%d \t \n", f.vetor[i]);
		}
	}
    //se estiver vazia, informa o usu�rio
	else {
		printf("\nA fila estah vazia.\n");
	}
}

int remover() {
	//verificar se a fila n�o est� vazia
	if (!verificarVazia()) {
		//define duas vari�veis aux e i
		int aux, i;

		//aux ir� guardar o elemento do in�cio da fila
		aux = f.vetor[0];

		//translada os elementos do inicio ao final -1
		for (i = 0; i < f.fim; i++) {
			//a posi��o i receber o valor da posi��o i+1
			f.vetor[i] = f.vetor[i + 1];
		}

		//atualiza o fim da fila
		f.fim--;

		//retorna n�mero removido
		return aux;
	}
	//se estiver vazia, informa o usu�rio
	else {
		printf("\nA fila estah vazia.\n");

		return -1;
	}
}