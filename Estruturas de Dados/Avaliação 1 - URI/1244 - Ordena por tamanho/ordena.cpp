#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 30

typedef struct{

char simbolos[30];

} SEQUENCIA;

SEQUENCIA criarSequencia(char* simbolos){

SEQUENCIA s;
strcpy(s.simbolos, simbolos);
return s;

}

typedef struct lista{
int cont;
SEQUENCIA dados[MAX];
struct lista *prox;

} LISTA;

LISTA* criarLista(){

	LISTA *l;
	l = (LISTA*)malloc(sizeof(LISTA));
	if(l != 0) {
	l->cont = 0;

	}
return l;

}

void destruirLista(LISTA* l){

free(l);

}

int listaVazia(LISTA* l){

if(l == 0) return -1;
else return l->cont == 0;

}

int listaCheia(LISTA* l){

if(l == 0) return -1;
else return l->cont == MAX;

}

SEQUENCIA s[MAX];

int inserirOrdenado(LISTA* l, SEQUENCIA s[MAX]){
	int i, posicao;
	if(l==NULL) return 0;
	if(listaCheia(l)) return 0;
	if(listaVazia(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(s[i].simbolos, s[i+1].simbolos) > 0); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = s[MAX];
	l->cont++;
	return 1;
}

void imprimirSequencia(LISTA *l, SEQUENCIA s[MAX]){ 
	
	for (int i=0; i<MAX; i++) {
		printf("%s", s[i].simbolos);
	}

}

void imprimirDadosLista(LISTA* l, SEQUENCIA s[MAX]){
	if(l != NULL){
		if(!listaVazia(l)){
			imprimirSequencia(l, s);
		}
}
}

/////////////////////////////////////////////////////////////////////////////////////////
LISTA* l;
/////////////////////////////////////////////////////////////////////////////////////////

int main() {

int casos;
char *sub;
char str[MAX];
char aux[MAX];

	scanf("%d", &casos);

	for (int k=0; k<casos+2; k++) {
	
		fgets(str, MAX, stdin);
		sub = strtok (str, " ");
	
		while (sub != NULL) {
		
		for (int i=MAX; i>=0; i--) {
			for (int j=1; j<i; j++) {
				if (strcmp(&sub[j-1], &sub[j]) == 1) {
					strcpy(aux, &sub[j-1]);
					strcpy(&sub[j], &sub[j-1]);
					strcpy(&sub[j], aux);
				}
			}
		}

		printf("%s ", sub);

		sub = strtok (NULL, " ");
	
	}
  }
	
return 0;
}