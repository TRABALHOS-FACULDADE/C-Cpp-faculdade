#include <stdio.h>
#include <stdlib.h>
#include "pilhaseq.h"

typedef struct no {
    int dados;
    struct no *prox;
} NO;

typedef NO* LISTA;

LISTA* cria_lista() {
    LISTA *l = (LISTA*) malloc(sizeof(LISTA));
    if (l != NULL)
        *l = NULL;
    return l;
}

int listaVazia(LISTA* l) {
    if (l == NULL) return 1;
    if ((*l) == NULL) return 1;
    return 0;
}

int tamanhoLista(LISTA *l);
int listaCheia(LISTA* l) { /* Função raramente utilizada */
    if (tamanhoLista(l) == MAX) return 1;
    else return 0;
}

void concatenarListas(LISTA* l, LISTA* l2) {
    NO* aux = *l;
    if (listaVazia(l)) {
        *l = *l2;
    } else {
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = *l2;
    }
}

int insereNaLista(LISTA* l, int c) {
    if (l==NULL) return 0;
    NO *novo_no = (NO*)malloc(sizeof(NO));
    if (novo_no == NULL) return 0;

    novo_no->dados = c;
    novo_no->prox = NULL;
    if ((*l) == NULL)
        *l = novo_no;
    else {
        NO *aux = *l;
        while (aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = novo_no;
    }
    return 1;
}

void inserirNoInicio(LISTA* l, int c) { /* Está inserindo na segunda posição ;-; */
    NO* novo_no = (NO*)malloc(sizeof(NO));
    NO* aux = *l;
    novo_no->dados = c;
    novo_no->prox = aux->prox;
    aux->prox = novo_no;
}

void removeElementoTopo(LISTA* l) { /* Está removendo o elemento da segunda posição ;-; */
    NO* trash;
    NO* aux = *l;
    trash = aux->prox;
    if (trash->prox == NULL) aux->prox = NULL;
    else aux->prox = trash->prox;
    free(trash);
}

void removerValor(LISTA *l, int valor){
	NO* aux = *l;
	NO* rem = *l;
	
	// Cuidado especial com a cabeça da lista!!!
	// Enquanto os dados a serem removidos estiverem na cabeça da lista
	// precisamos deslocar a cabeça da lista para o próximo
	while(aux->dados == valor){
		rem = aux;
		(*l) = aux->prox; // Desloca o no cabeca para o proximo
		free(rem);
		aux = *l;
	}
	
	// Não há mais dados a serem removidos da cabeça da lista
	// Remove os demais dados da lista
	while(aux->prox!=NULL){
		if(aux->prox->dados == valor){
			rem = aux->prox;
			aux->prox = aux->prox->prox;
			rem->prox = NULL;
			free(rem);
		}
		else aux=aux->prox;
	}
}

void insereAcima(LISTA *l, int x, int y) {
    /* Insere o elemento x acima do elemento y */
    NO *p, *q, *novo;
    NO* aux = *l;
    NO* novo_no = (NO*)malloc(sizeof(NO));
    novo_no->dados = x;
    p = aux;
    q = aux->prox;
    while (q != NULL && q->dados != y) {
        p = q;
        q = q->prox;
    }
    novo_no->prox = q;
    p->prox = novo_no;
}

int imprimeLista(LISTA *l) {
    NO *aux = *l;
    while (aux != NULL) {
        printf("%d", aux->dados);
        aux = aux->prox;
    }
    printf("\n");   
}

int tamanhoLista(LISTA *l) { /* Devolve o tamanho da lista */
    int cont=0;
    NO *atual = *l;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
}

LISTA* clonarReversa(LISTA* l) {
    NO *aux = *l;
    Pilha *p;
    LISTA *lRet;
    lRet = cria_lista();
    p = criarPilha();

    while (aux != NULL) {
        empilhar(p, aux->dados);
        aux = aux->prox;
    }

    while (!estahVaziaPilha(p)) {
        insereNaLista(lRet, desempilhar(p));
    }
    return lRet;
}

void destroiLista(LISTA *l) {
    NO *atual = *l;
    while (atual != NULL) {
        *l = atual->prox;
        free(atual);
        atual = *l;
    }
    *l = NULL;
}