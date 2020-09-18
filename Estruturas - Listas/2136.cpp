#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 30

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct{

char nome[30];
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

int inserirNoFinal(LISTA* l, AMIGO a){

if(l==0) return 0;
if(listaCheia(l)) return 0;
l->dados[l->cont] = a;
l->cont++;
return 1;

}

int inserirNoInicio(LISTA* l, AMIGO a){

int i;
if(l==0) return 0;
if(listaCheia(l)) return 0;
for(i=l->cont-1; i>=0; i--){

l->dados[i+1] = l->dados[i];

}
l->dados[0] = a;
l->cont++;
return 1;

}

int inserirNoMeio(LISTA* l, AMIGO a, int
posicao){
int i;
if(l==0) return 0;
if(listaCheia(l)) return 0;
for(i=l->cont-1; i>=posicao; i--){
	l->dados[i+1] = l->dados[i];
}
l->dados[posicao] = a;
l->cont++;
return 1;
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

void amigoHabay(AMIGO a[MAX]) {
	
	printf("\n");
	for (int i=0; i<MAX; i++){
		if (strcmp(a[i].resposta, "YES") == 0) {
			printf("\nAmigo do Habay:\n%s", a[i].nome);
			break; /// vai interromper o LOOP assim que encontrar o primeiro "YES"
		}
	}
}

ordenaStrings(AMIGO a[MAX]) { //// Booble sort

char aux[100];
int r;

for (int i=0; i<MAX; i++){
	for (int j=i+1; j<MAX; j++){
		r = strcmp(a[i].nome, a[j].nome);
		if (r > 0){
			strcpy(aux, a[i].nome);
			strcpy(a[i].nome, a[j].nome);
			strcpy(a[j].nome, aux);
		}
	}
}
}

void imprimirAmigo(LISTA *l, AMIGO a[MAX]){ 
	
	// YES
	for (int i=0; i<MAX; i++) {
		if (strcmp(a[i].resposta, "YES") == 0) {
			printf("%s\n", a[i].nome);
	}
}

	// NO
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
	}
}

imprimirDadosLista(l, a);
amigoHabay(a);
return 0;
}
