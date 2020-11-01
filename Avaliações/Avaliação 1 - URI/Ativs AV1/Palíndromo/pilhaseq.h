#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 10

typedef struct{
	char letras[100];
} PALAVRA;

PALAVRA criarPalavra(char* letras){
	PALAVRA pa;
	strcpy(pa.letras, letras);
	return pa;
}

typedef struct{
	int topo;
	PALAVRA dados[MAX];
} PILHA;

PILHA* criarPilha(){
	PILHA *p;
	p = (PILHA*)malloc(sizeof(PILHA));
	if(p != NULL){
		p->topo = 0;
	}
	return p;
}

void destruirPilha(PILHA* p){
	free(p);
}

int pilhaVazia(PILHA* p){
	if(p == NULL) return -1;
	else return p->topo == 0;
}

int pilhaCheia(PILHA* p){
	if(p == NULL) return -1;
	else return p->topo == MAX;
}

int empilhar(PILHA* p, PALAVRA pa){
	if(p==NULL) return 0;
	if(pilhaCheia(p)) return 0;
	p->dados[p->topo] = pa;
	p->topo++;
	return 1;
}

PALAVRA desempilhar(PILHA *p) { 
	PALAVRA temp;
	if(p != NULL || !pilhaVazia(p)){	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

void imprimirPalavra(PALAVRA pa){
	printf("%s\n", pa.letras);
}

void imprimirDadosPilha(PILHA* p){
	int i;
	if(p != NULL){
		if(!pilhaVazia(p)){
			for(i=p->topo-1; i>=0; i--){
				imprimirPalavra(p->dados[i]);
			}
		}else{
			printf("Pilha esta vazia!\n");
		}
	}else{
		printf("Pilha nao foi criada!\n");
	}
}

