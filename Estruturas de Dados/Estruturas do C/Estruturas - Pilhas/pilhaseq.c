#include <stdio.h>
#include <string.h>
#include "pilhaseq.h"

Pilha *p;

int main(){	
	Carta c;
	
	p = criarPilha();	
	if(p != NULL) printf("Pilha criada com sucesso contendo %d elementos!\n", p->topo);
	
	c = criarCarta("As", "Copas", 1); 	
	empilhar(p, c); 

	c = criarCarta("Rei", "Espada", 13); 	
	empilhar(p, c); 

	c = criarCarta("Duque", "Ouro", 2); 	
	empilhar(p, c); 

	c = criarCarta("Dez", "Paus", 10); 	
	empilhar(p, c); 

	printf("Pilha agora tem %d elementos!\n", p->topo);
	imprimirDadosPilha(p);
	
	c = desempilhar(p);
	printf("Carta desempilhada:\n");
	imprimirCarta(c);
	
	printf("Pilha agora tem %d elementos!\n", p->topo);
	imprimirDadosPilha(p);	

	destruirPilha(p);
	printf("Pilha destruida com sucesso!\n");
}
