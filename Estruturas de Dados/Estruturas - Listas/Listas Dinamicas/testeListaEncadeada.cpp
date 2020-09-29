#include "listaencint.h"

LISTA *l; // Ponteiro para Ponteiro (nó cabeça)

int main(){
	
	l = cria_lista();
	
	insereNaLista(l, 2);
	insereNaLista(l, 3);
	insereNaLista(l, 2);
	insereNaLista(l, 5);
	insereNaLista(l, 10);
	insereNaLista(l, 290);
	insereNaLista(l, 3);
	insereNaLista(l, 2);
    inserirNoInicio(l, 99);
    inserirNoInicio(l, 77);
	removeElementoTopo(l);

	imprimeLista(l);
    printf("\nTamanho da lista: %d", tamanhoLista(l));

	destroiLista(l);
	
	return 0;
}