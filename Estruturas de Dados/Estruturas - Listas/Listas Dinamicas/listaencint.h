#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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
    aux->prox = trash->prox;
    free(trash);
}

int imprimeLista(LISTA *l) {
    NO *aux = *l;
    while (aux != NULL) {
        printf("%d", aux->dados);
        aux = aux->prox;
    }
    printf("\n");   
}

int tamanhoLista(LISTA *l) {
    int cont=0;
    NO *atual = *l;
    while (atual != NULL) {
        cont++;
        atual = atual->prox;
    }
    return cont;
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