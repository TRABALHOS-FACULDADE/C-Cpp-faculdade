#include "listaencint.h"

LISTA *l; // Ponteiro para Ponteiro (nó cabeça)

int main(){
	
	l = cria_lista();
	
	insereNaLista(l, 2);
	insereNaLista(l, 5);
	insereNaLista(l, 10);
	insereNaLista(l, 290);
	insereNaLista(l, 3);
    inserirNoInicio(l, 99);
    inserirNoInicio(l, 77);
	removeElementoEspecifico(l, 99);
	insereAcima(l, 88, 290);
	insereAcima(l, 33, 77);
	insereAcima(l, 123, 2);

	imprimeLista(l);
    printf("\nTamanho da lista: %d", tamanhoLista(l));

	destroiLista(l);
	
	return 0;
}