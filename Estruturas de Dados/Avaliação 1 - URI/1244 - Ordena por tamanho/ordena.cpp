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

void ordenaStrings(char* nome[MAX]) { //// Booble sort

char* aux[MAX];
int r;

for (int i=MAX; i>=0; i--){
	for (int j=1; j<=i; j++){
		r = strcmp(nome[j-1], nome[j]);
		if (r == 1){
			aux[MAX] = nome[j-1];
			nome[j-1] = nome[j];
			nome[j] = aux[MAX];
		}
	}
}
}

int main() {

int casos;
char frase[MAX];

	scanf("%d", &casos);

	for (int i=1; i<casos+2; i++) {

		p = criarPilha();
		fgets(frase, MAX, stdin);

	}
	
return 0;
}