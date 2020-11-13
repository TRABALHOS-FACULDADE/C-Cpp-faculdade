#include "listaencint.h"

LISTA *l; // Ponteiro para Ponteiro (nó cabeça)
LISTA *l2;

int main(){
	
	l = cria_lista();

    if (listaVazia(l)) {
        insereOrdenado(l, 30);
        insereOrdenado(l, 15);
        insereOrdenado(l, 7);
        insereOrdenado(l, 57);
        insereOrdenado(l, 89);
        insereOrdenado(l, 75);
        insereOrdenado(l, 33);
        insereOrdenado(l, 9);
    }

    imprimeLista(l);

return 0;
}