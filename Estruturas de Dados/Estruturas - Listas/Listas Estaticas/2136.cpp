#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 30

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct{

char nome[MAX];
char resposta[5];

} AMIGO;

AMIGO criarAmigo(char* nome, char* resposta){

AMIGO a;
strcpy(a.nome, nome);
strcpy(a.resposta, resposta);
return a;

}

typedef struct lista{
int cont;
AMIGO dados[MAX];
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

int inserirOrdenado(LISTA* l, AMIGO a){
	int i, posicao;
	if(l==NULL) return 0;
	if(listaCheia(l)) return 0;
	if(listaVazia(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(l->dados[i].nome, a.nome) > 0); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = a;
	l->cont++;
	return 1;
}

int buscaSequencial(LISTA *l, char *nome){
	int i;
	if(l != NULL){
		if(!listaVazia(l)){
			for(i=0; i<l->cont; i++){
				if(strcmp(nome, l->dados[i].nome) == 0)
					return i;
			}
		}else{
			return -1;
		}		
	}else{
		return -1;
	}
}

int remover(LISTA *l, char* nome){
	int i;
	int posRem; 
	
	if(l == NULL) return -1;
	if(listaVazia(l)) return -1;
	
	posRem = buscaSequencial(l, nome);
	
	// Se encontrou o nome para remover
	if(posRem >= 0){
		// Desloca os AMIGOS que estiverem à direita da posicao encontrada, 1 casa para esquerda
		for(i=posRem; i<l->cont; i++){
			l->dados[i] = l->dados[i+1];
		}
		l->cont--; // Nâo é preciso remover o último item do vetor, pois o cont controla essa informacao	
	}	
}

void ordenaStrings(AMIGO a[MAX]) { //// Booble sort

AMIGO aux;
int r;

for (int i=MAX; i>=0; i--){
	for (int j=1; j<=i; j++){
		r = strcmp(a[j-1].nome, a[j].nome);
		if (r == 1){
			aux = a[j-1];
			a[j-1] = a[j];
			a[j] = aux;
		}
	}
}
}

void imprimirAmigo(LISTA *l, AMIGO a[MAX]){ 

	// YES
	printf("\n");
	ordenaStrings(a);
	for (int i=0; i<MAX; i++) {
		if (strcmp(a[i].resposta, "YES") == 0) {
			printf("%s\n", a[i].nome);
	}
}

	// NO
	ordenaStrings(a);
	for (int i=0; i<MAX; i++) {
		if (strcmp(a[i].resposta, "NO") == 0) {
			printf("%s\n", a[i].nome);
	}
}

}

void imprimirDadosLista(LISTA* l, AMIGO a[MAX]){
	int i;
	if(l != NULL){
		if(!listaVazia(l)){
			imprimirAmigo(l, a);
		}
}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

LISTA* l;
AMIGO a[MAX];

int main() {

setlocale(LC_ALL, "portuguese");

char fim[5] = "FIM";
char guarda[MAX];

l = criarLista();

for (int i = 0; i<= MAX; i++){
	scanf("%s %s", a[i].nome, a[i].resposta);
	
	if (strcmp(a[i].nome, "FIM") == 0) {
		remover(l, a[i].nome);
		//strcpy(a[i].nome, "");
		break;
		/*
		A função strcmp(..., ...) serve para comparar duas strings por meio de um resultado binário.
		Documentação: (http://www.cplusplus.com/reference/cstring/strcmp/)
		*/
	} else {
		a[i] = criarAmigo(a[i].nome, a[i].resposta);
		inserirOrdenado(l, a[i]);
		
		for (int i=0; i<MAX; i++) {
			if (strcmp(a[i].resposta, "YES") == 0){
				strcpy(guarda, a[i].nome);
				break;
		}
		}
	}
}

imprimirDadosLista(l, a);
printf("\nAmigo do Habay:\n%s", guarda);
return 0;
}
