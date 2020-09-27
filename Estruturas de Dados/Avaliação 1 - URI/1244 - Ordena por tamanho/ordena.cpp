#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 30

typedef struct{
	char nomes[MAX];
} PALAVRA;

PALAVRA criarPalavra(char* nomes){
	PALAVRA pa;
	strcpy(pa.nomes, nomes);
	return pa;
}

typedef struct lista{
int cont;
PALAVRA dados[MAX];
struct lista *prox;

} LISTA;

LISTA* criarLista(){

LISTA *l;
l = (LISTA*)malloc(sizeof(LISTA));
if(l != 0){
l->cont = 0;

}
return l;

}

int listaVazia(LISTA* l){

if(l == 0) return -1;
else return l->cont == 0;

}

int listaCheia(LISTA* l){

if(l == 0) return -1;
else return l->cont == MAX;

}

int inserirOrdenado(LISTA* l, PALAVRA pa){
	int i, posicao;
	if(l==NULL) return 0;
	if(listaCheia(l)) return 0;
	if(listaVazia(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(l->dados[i].nomes, pa.nomes) > 0); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = pa;
	l->cont++;
	return 1;
}
////////////////////////////////////////////////////////////////////////////////////////////////
void BubbleSort(PALAVRA pa[MAX]);
void excluiLista(LISTA* l) {free(l);}
void imprimirPalavras(LISTA *l, PALAVRA pa[MAX], int casos);
void imprimirDadosLista(LISTA* l, PALAVRA pa[MAX], int casos);

void BubbleSort(PALAVRA pa[MAX]) {
	bool swapped = true;
	int j = 0;
	PALAVRA temp;
	
	while (swapped) {
		swapped = false;
		j++;
		for (int i=0; i<MAX-j; i++) {
			if (strcmp(pa[i].nomes, pa[i+1].nomes) > 0) {
				temp = pa[i];
				pa[i] = pa[i+1];
				pa[i+1] = temp;
				swapped = true;
			}
		}
	}
}

void imprimirPalavras(LISTA *l, PALAVRA pa[MAX], int casos){ 

	for (int i=0; i<casos; i++){
		printf("\n%s\n", pa[i].nomes);
	}
	
}

void imprimirDadosLista(LISTA* l, PALAVRA pa[MAX], int casos){
	if(l != NULL){
		if(!listaVazia(l)){
			imprimirPalavras(l, pa, casos);
		}
}
}
/////////////////////////////////////////////////////////////////////////////////////////
LISTA* l;
PALAVRA pa[MAX];
/////////////////////////////////////////////////////////////////////////////////////////
int main() {

int casos;
	
	scanf("%d", &casos);
	for (int i=0; i<casos+1; i++) {
		
		l = criarLista();
		
		fgets(pa[i].nomes, MAX, stdin);
		pa[i] = criarPalavra(pa[i].nomes);
		inserirOrdenado(l, pa[i]);
		BubbleSort(pa);
		imprimirDadosLista(l, pa, casos);
		
		excluiLista(l);
		
	}
	
return 0;
}
