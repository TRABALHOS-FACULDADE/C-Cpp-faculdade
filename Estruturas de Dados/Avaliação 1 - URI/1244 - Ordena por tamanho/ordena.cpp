#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct{
	char* simbolos;
} SEQUENCIA;

SEQUENCIA criarSequencia(char* simbolos){
	SEQUENCIA s;
	strcpy(s.simbolos, simbolos);
	return s;
}

typedef struct{
	int topo;
	char dados[MAX];
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

int empilhar(PILHA* p, char s){
	if(p==NULL) return 0;
	if(pilhaCheia(p)) return 0;
	p->dados[p->topo] = s;
	p->topo++;
	return 1;
}

/////////////////////////////////////////////////////////////////////////////////////////
PILHA* p;
SEQUENCIA s;
/////////////////////////////////////////////////////////////////////////////////////////
int main() {

int casos;
char frase[MAX];

	int eof = 0;

	while (1) {
		if(scanf("%d", &eof) == EOF) break;

		p = criarPilha();
		fgets(frase, MAX, stdin);
		//empilhar(p, frase[MAX]);
	}
	
return 0;
}