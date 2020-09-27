#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct{
	char* simbolos;
} SEQUENCIA;

SEQUENCIA criarCarro(char* simbolos){
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

void destruirPilhas(PILHA* p, PILHA* p2) {
    destruirPilha(p);
    destruirPilha(p2);
}

///////////////////////////////////////////////////////////////////////////////////////////////
PILHA* p;
PILHA* p2;
SEQUENCIA s;

///////////////////////////////////////////////////////////////////////////////////////////////

int main () {
    
    char equacao[MAX];

    int eof = 0;

    while(1) {

        if(scanf("%d", &eof) == EOF) break;
        scanf("%s", equacao);

        p = criarPilha(); 
        p2 = criarPilha();
        int cont = 0;
        int cont2 = 0;

        for (int i=0; i<strlen(equacao); i++) {

            if (equacao[0] == ')') {
                cont2 ++;
            }

            if (equacao[i] == '(') {
                empilhar(p, equacao[i]);
            } else if (equacao[i] == ')') {
                empilhar(p2, equacao[i]);
            } else if (equacao[i] == '-') {
                cont++;
            }
        }

        if (p->dados[p->topo] == p2->dados[p2->topo] || cont%2==0 && cont!=0) {
            printf("correct\n");
                destruirPilhas(p, p2);
        } else if (p->dados[p->topo] != p2->dados[p2->topo]) {
            printf("incorrect\n");
                destruirPilhas(p, p2);
        }
    }

    return 0;
}