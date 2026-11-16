#include <stdio.h>
#include "lista.h"

int main(int argc, char *argv[]) {
	int temp, posicao;
	int opcao;
	inicializar();

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Realizar testes de inicializar a lista");
		printf("\n6. Realizar testes de inserir na lista");
		printf("\n7. Realizar testes de remover na lista");
		printf("\n8. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				printf("Digite o numero: ");
				scanf("%d", &temp);
				printf("Digite a posicao: ");
				scanf("%d", &posicao);
				inserir(temp, posicao);
				break;
			case 3:
				printf("Digite a posicao: ");
				scanf("%d", &posicao);
				temp = remover(posicao);
				printf("\nNumero removido: %d na posicao: %d", temp, posicao);
				break;
			case 4:
				imprimir();
				break;
			case 5:
				testar1_VaziaLista();
				break;
			case 6:
				testar2_InserirLista(1);
				testar2_InserirLista(2);
				testar2_InserirLista(3);
				testar2_InserirLista(4);
				testar2_InserirLista(5);
				break;
			case 7:
				testar3_RemoverLista();
				testar4_RemoverLista(1);
				testar4_RemoverLista(2);
				testar4_RemoverLista(3);
				testar4_RemoverLista(4);
				testar4_RemoverLista(5);
				break;
			case 8:
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 8);
}
