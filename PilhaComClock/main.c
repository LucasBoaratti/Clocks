#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "pilha.h"

int main(int argc, char *argv[]) {
	int temp, opcao, quantidade;
	double start, finish, elapsed;

	printf("\nDigite a quantidade de elementos para testar: ");
	scanf("%d", &quantidade);

	inicializar();

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				// Validacao de quantidade de elementos
				if (quantidade < 0 || quantidade > TAM_MAX) {
					printf("\nDigite uma quantidade valida.\n");

					break;
				}

				// Guardando o valor do clock antes de executar as chamadas da funcao
				start = (double) clock();

				// Laco for que insere a quantidade de elementos desejados
				for (int i = 0; i < quantidade; i++) {
					temp = obterDado();

					push(temp);

					exibirDado(temp);
				}

				// Guardando o valor do clock após executar as chamadas da funcao
				finish = (double) clock();

				// Calculando a diferenca de clocks entre o depois e antes das chamadas
				elapsed = finish - start;

				// Imprimindo na tela, a quantidade de clocks gastos
				printf("\nForam utilizados %.2f clocks", elapsed);

				break;
			case 3:
				// Validacao de quantidade de elementos
				if (quantidade < 0 || quantidade > TAM_MAX) {
					printf("\nDigite uma quantidade valida.\n");

					break;
				}

				// Guardando o valor do clock antes de executar as chamadas da funcao
				start = (double) clock();

				// Laco for que insere a quantidade de elementos desejados
				for (int i = 0; i < quantidade; i++) {
					temp = pop();

					exibirDado(temp);
				}

				// Guardando o valor do clock após executar as chamadas da funcao
				finish = (double) clock();

				// Calculando a diferenca de clocks entre o depois e antes das chamadas
				elapsed = finish - start;

				// Imprimindo na tela, a quantidade de clocks gastos
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 4:
				// Guardando o valor do clock antes de executar as chamadas da funcao
				start = (double) clock();

				imprimir();

				// Guardando o valor do clock após executar as chamadas da funcao
				finish = (double) clock();

				// Calculando a diferenca de clocks entre o depois e antes das chamadas
				elapsed = finish - start;

				// Imprimindo na tela, a quantidade de clocks gastos
				printf("\nForam utilizados %.2f clocks", elapsed);

				break;
			case 5:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");

				break;
		}
		
	} while(opcao != 5);
}