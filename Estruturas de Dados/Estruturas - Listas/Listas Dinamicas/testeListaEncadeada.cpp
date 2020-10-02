#include "listaencint.h"

LISTA *l; // Ponteiro para Ponteiro (nó cabeça)
LISTA *l2;

int main(){
	
	l = cria_lista();
	
	if (listaVazia(l)) {

	insereNaLista(l, 2);
	insereNaLista(l, 5);
	insereNaLista(l, 10);
	insereNaLista(l, 290);
	insereNaLista(l, 3);
    inserirNoInicio(l, 99);
    inserirNoInicio(l, 77);
	removerValor(l, 99);
	insereAcima(l, 88, 290);
	insereAcima(l, 33, 77);
	insereAcima(l, 123, 2);
	}

	l2 = cria_lista();

	if (listaVazia(l2)) {
		insereNaLista(l2, 33);
		insereNaLista(l2, 4);
		insereNaLista(l2, 5);
		insereNaLista(l2, 6);
		insereNaLista(l2, 7);
		insereNaLista(l2, 38);
	}

	imprimeLista(l);
	printf("\nTamanho da lista: %d\n\n", tamanhoLista(l));

	concatenarListas(l, l2);

	imprimeLista(l);
    printf("\nTamanho da lista concatenada: %d", tamanhoLista(l));

	destroiLista(l);

	return 0;
}