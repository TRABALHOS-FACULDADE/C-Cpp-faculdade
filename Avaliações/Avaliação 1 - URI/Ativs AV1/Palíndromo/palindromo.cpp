#include "pilhaseq.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <locale.h>

PILHA* p;
PALAVRA pa;

int palavraPalindromo(PALAVRA pa, PALAVRA pa2) {
	
	int len;
	len = strlen(pa.letras);
	
	for(int i = 0; i<len; i++) {
		if(pa.letras[i] != pa2.letras[((len - i) - 1)]) {
			return 0;
		}
	}
	return 1;

	imprimirDadosPilha(p);
	
}

PILHA* iniciarPilha(PALAVRA pa){	
	
	p = criarPilha();
	empilhar(p, pa); /* P A L A V R A */ //pilha empilhada
	//				  base         topo
	
	return p;
}

int main() {
		
	setlocale(LC_ALL, "portuguese");
	
	int len;
	PALAVRA palavraTopo;
	
	printf("Informe uma palavra: "); scanf(" %[^\n]s", &pa.letras);
	p = iniciarPilha(pa);
	palavraTopo = desempilhar(p); /* A R V A L A P */ // pilha desempilhada
	//					    base         topo
	
	if (palavraPalindromo(pa, palavraTopo)) {
		printf("\nÉ palíndromo!\n");
	} else {
		printf("\nNão é palíndromo!\n");
	}
	
return 0;
}