#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

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

void destruirPilhas(PILHA* p, PILHA* p2) {
    destruirPilha(p);
    destruirPilha(p2);
    /// printf("Pilhas destruidas!\n");
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
        fgets(equacao, MAX, stdin);

        p = criarPilha(); 
        p2 = criarPilha();

        int tam = strlen(equacao);
        for (int i=0; i<tam; i++) {

            if (equacao[i] == '(') {
                empilhar(p, equacao[i]);
            } else if (equacao[i] == ')' && (p2->topo != 0)) {
                break;
            } else if (equacao[i] == ')') {
                empilhar(p2, equacao[i]);
            }
        }

        if (p->topo == p2->topo) {
            printf("correct\n");
            destruirPilhas(p, p2);
        } else if (p->topo != p2->topo) {
            printf("incorrect\n");
            destruirPilhas(p, p2);
        }
    }

    return 0;
}