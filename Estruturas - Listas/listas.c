#define max 100
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct{

char marca[30];
char placa[9];
char modelo[50];
int tipoMarcha; // 1=Auto, 2=Manual
int qtdPortas;

} VEICULO;

VEICULO criarVeiculo(char* placa, char*
modelo, char* marca, int qportas, int
tmarcha){

VEICULO v;
strcpy(v.marca, marca);
strcpy(v.modelo, modelo);
strcpy(v.placa, placa);
v.qtdPortas = qportas;
v.tipoMarcha = tmarcha;
return v;

}

typedef struct{
int cont;
VEICULO dados[max];

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

int estahVazia(Lista* l){

if(l == 0) return -1;
else return l->cont == 0;

}

int estahCheia(Lista* l){

if(l == 0) return -1;
else return l->cont == max;

}

int inserirNoFinal(Lista* l, VEICULO v){

if(l==0) return 0;
if(estahCheia(l)) return 0;
l->dados[l->cont] = v;
l->cont++;
return 1;

}

int inserirNoInicio(Lista* l, VEICULO v){

int i;
if(l==0) return 0;
if(estahCheia(l)) return 0;
for(i=l->cont-1; i>=0; i--){

l->dados[i+1] = l->dados[i];

}
l->dados[0] = v;
l->cont++;
return 1;

}

int inserirNoMeio(Lista* l, VEICULO v, int
posicao){
int i;
if(l==0) return 0;
if(estahCheia(l)) return 0;
for(i=l->cont-1; i>=posicao; i--){
l->dados[i+1] = l->dados[i];

}
l->dados[posicao] = v;
l->cont++;
return 1;

}

Lista *l;

int main(){

l = criarLista();
if(l != 0) printf("Lista criada contendo %d elementos!\n", l->cont);

destruirLista(l);
printf("Lista foi destruida!\n");

}
