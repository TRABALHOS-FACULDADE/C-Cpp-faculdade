#define MAX 10
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>

typedef struct{

char cor[10];
char placa[9];
char modelo[150];

} VEICULO;

VEICULO criarVeiculo(char* placa, char* modelo, char* cor){

VEICULO v;
strcpy(v.cor, cor);
strcpy(v.modelo, modelo);
strcpy(v.placa, placa);

return v;

}

typedef struct{
int cont;
VEICULO dados[MAX];

} Lista;

Lista* criarLista(){

Lista *l;
l = (Lista*)malloc(sizeof(Lista));
if(l != 0){
l->cont = 0;

}
return l;

}

void destruirLista(Lista* l){

free(l);

}

int listaVazia(Lista* l){

if(l == 0) return -1;
else return l->cont == 0;

}

int listaCheia(Lista* l){

if(l == 0) return -1;
else return l->cont == MAX;

}

int inserirNoFinal(Lista* l, VEICULO v){

if(l==0) return 0;
if(listaCheia(l)) return 0;
l->dados[l->cont] = v;
l->cont++;
return 1;

}

int inserirNoInicio(Lista* l, VEICULO v){

int i;
if(l==0) return 0;
if(listaCheia(l)) return 0;

for(i=l->cont-1; i>=0; i--) {
	l->dados[i+1] = l->dados[i];
}
	
l->dados[0] = v;
l->cont++;
return 1;
}

int inserirNoMeio(Lista* l, VEICULO v, int posicao) {

int i;
if(l==0) return 0;
if(listaCheia(l)) return 0;

for(i=l->cont-1; i>=posicao; i--){
	l->dados[i+1] = l->dados[i];
}

l->dados[posicao] = v;
l->cont++;
return 1;
}


int inserirOrdenado(Lista* l, VEICULO v){
	int i, posicao;
	if(l==NULL) return 0;
	if(listaCheia(l)) return 0;
	if(listaVazia(l)) 
		posicao = 0;
	else{ // Acha a posicao para inserir
		for(i=l->cont-1; i>=0 && (strcmp(l->dados[i].cor, v.cor) > 0); i--){
			l->dados[i+1] = l->dados[i];
		}
		posicao = i+1;
	}
	l->dados[posicao] = v;
	l->cont++;
	return 1;
}

void imprimirVeiculo(Lista *l, VEICULO v[MAX], int quantCar){ 

setlocale(LC_ALL, "portuguese");
	
	for (int i=0; i<quantCar; i++) {
		printf("\n============Veículo %d============\n", i+1);
		printf("Placa: %s\n", v[i].placa);
		printf("Modelo: %s\n", v[i].modelo);
		printf("Cor: %s\n", v[i].cor);
		printf("=====================================\n");
	}
}

void imprimirDadosLista(Lista* l, VEICULO v[MAX], int quantCar){
	if(l != NULL){
		if(!listaVazia(l)){
			imprimirVeiculo(l, v, quantCar);
		}
}
}

void ordenaVeiculos(Lista* l, VEICULO v[MAX], int quantCar) { //// Booble sort

VEICULO aux;
int r;

for (int i=quantCar; i>=0; i--) {
	for (int j=1; j<=i; j++) {
		if (strcmp(v[j-1].cor, "Preto") == 0) {
			printf("\n============Veículo===============\n");
			printf("Placa: %s\n", v[j-1].placa);
			printf("Modelo: %s\n", v[j-1].modelo);
			printf("Cor: %s\n", v[j-1].cor);
			printf("=====================================\n");
		}
	}
	for (int j=1; j<=i; j++) {
		if (strcmp(v[j-1].cor, "Branco") == 0) {
			printf("\n============Veículo===============\n");
			printf("Placa: %s\n", v[j-1].placa);
			printf("Modelo: %s\n", v[j-1].modelo);
			printf("Cor: %s\n", v[j-1].cor);
			printf("=====================================\n");
		}
	}
	for (int j=1; j<=i; j++) {
		if (strcmp(v[j-1].cor, "Vermelho") == 0) {
			printf("\n============Veículo===============\n");
			printf("Placa: %s\n", v[j-1].placa);
			printf("Modelo: %s\n", v[j-1].modelo);
			printf("Cor: %s\n", v[j-1].cor);
			printf("=====================================\n");
		}
	}
	break;
	}
}