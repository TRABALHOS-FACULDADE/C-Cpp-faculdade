#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define MAX 10

typedef struct{
	char letras[100];
} PALAVRA;

PALAVRA criarPalavra(char* letras){
	PALAVRA pa;
	strcpy(pa.letras, letras);
	return pa;
}

typedef struct{
	int topo;
	PALAVRA dados[MAX];
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

int empilhar(PILHA* p, PALAVRA pa){
	if(p==NULL) return 0;
	if(pilhaCheia(p)) return 0;
	p->dados[p->topo] = pa;
	p->topo++;
	return 1;
}

PALAVRA desempilhar(PILHA *p) { 
	PALAVRA temp;
	if(p != NULL || !pilhaVazia(p)){	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	}else{
		return temp;
	}
}

void imprimirPalavra(PALAVRA pa){
	printf("%s\n", pa.letras);
}

void imprimirDadosPilha(PILHA* p){
	int i;
	if(p != NULL){
		if(!pilhaVazia(p)){
			for(i=p->topo-1; i>=0; i--){
				imprimirPalavra(p->dados[i]);
			}
		}else{
			printf("Pilha esta vazia!\n");
		}
	}else{
		printf("Pilha nao foi criada!\n");
	}
}


////////////////////////////////////////////////////////////////////////////////////////////////

PILHA* p;
PALAVRA pa;

int palavraPalindromo(PALAVRA pa, PALAVRA pa2) {
	
	int len;
	len = strlen(pa.letras);
	
	for(int i = 0; i<len; i++) {
		if(pa.letras[i] != pa2.letras[((len - i) - 1)]) {
			return 0;
		}
	}
	return 1;

	imprimirDadosPilha(p);
	
}

PILHA* iniciarPilha(PALAVRA pa){	
	
	p = criarPilha();
	empilhar(p, pa); /* P A L A V R A */ //pilha empilhada
	//				  base         topo
	
	return p;
}

int main() {
		
	setlocale(LC_ALL, "portuguese");
	
	int len;
	PALAVRA palavraTopo;
	
	printf("Informe uma palavra: "); scanf(" %[^\n]s", &pa.letras);
	p = iniciarPilha(pa);
	palavraTopo = desempilhar(p); /* A R V A L A P */ // pilha desempilhada
	//					    base         topo
	
	if (palavraPalindromo(pa, palavraTopo)) {
		printf("\nÉ palíndromo!\n");
	} else {
		printf("\nNão é palíndromo!\n");
	}
	
return 0;
}