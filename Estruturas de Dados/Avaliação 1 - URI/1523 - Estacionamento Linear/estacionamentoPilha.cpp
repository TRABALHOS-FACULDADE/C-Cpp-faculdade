#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct{
	int chegada, saida;
} CARRO;

CARRO criarCarro(int chegada, int saida){
	CARRO c;
	c.chegada = chegada;
	c.saida = saida;
	return c;
}

typedef struct{
	int topo;
	CARRO dados[MAX];
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

int pilhaCheia(PILHA* p, int vagas){
	if(p == NULL) return -1;
	else return p->topo == vagas;
}

int empilhar(PILHA* p, CARRO c, int vagas){
	if(p==NULL) return 0;
	if(pilhaCheia(p, vagas)) return 0;
	p->dados[p->topo] = c;
	p->topo++;
	return 1;
}

CARRO desempilhar(PILHA *p) { 
	CARRO temp;
	if(p != NULL || !pilhaVazia(p)) {	
		p->topo--;  // Reduz o topo para retirar
		temp = p->dados[p->topo];
		return temp;
	} else {
		return temp;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////
PILHA* p;
CARRO c;
/////////////////////////////////////////////////////////////////////////////////////////////////
void checaPossibilidade(int cont, int vagas);
static int horario = 13;

void fluxoEstacionamento(CARRO c, PILHA* p, int carros, int cont,  int vagas) {
	for (int i=0; i<carros; i++) {
		scanf("%d %d", &c.chegada, &c.saida);
		c = criarCarro(c.chegada, c.saida);
	}
	
	for (int i=1; i<horario; i++) {
		if (i == c.chegada) {
			empilhar(p, c, vagas);
			cont++;
		} else if (i == c.saida){
			if (p->dados[p->topo].saida != p->dados[i-1].saida) {
				cont += 5;
			}
			desempilhar(p);
			cont--;
		}
	}

	checaPossibilidade(cont, vagas);
}

void checaPossibilidade(int cont, int vagas) {
	
	//printf("\n%d\n", cont);
	
	if (cont <= vagas) {
		printf("Sim\n");
	} else if (cont > vagas || pilhaCheia(p, vagas)){
		printf("Nao\n");
	}
}

int main() {
	
int carros, vagas;

while (1) {
int cont = 0;	
	p = criarPilha();
	
	scanf("%d %d", &carros, &vagas);
	if (carros == 0 && vagas == 0) break;
	fluxoEstacionamento(c, p, carros, cont, vagas);
	
	destruirPilha(p);
}

return 0;
}