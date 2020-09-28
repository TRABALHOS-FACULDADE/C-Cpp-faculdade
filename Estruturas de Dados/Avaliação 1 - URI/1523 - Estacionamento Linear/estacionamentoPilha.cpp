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

/* Essa função vai percorrer uma variável i de 1 até o horário final da saída do último carro.
Enquanto percorrer essa variável, será feita a comparação com os dados de entrada e saída dos carros
na pilha. Quando i se igualar a esses horários, serão feitas as ações de empilhar e empilhar. */

	for (int i=0; i<carros; i++) { /// loop para cadastrar os horários de chegada e saída dos carros 
		scanf("%d %d", &c.chegada, &c.saida);
		c = criarCarro(c.chegada, c.saida);
	}
	
	for (int i=1; i<horario; i++) { /// loop para percorrer as horas e controlar o fluxo na garagem
		if (i == c.chegada) {
			empilhar(p, c, vagas);
			cont++;
		} else if (i == p->dados[p->topo].saida){
			if (p->dados[p->topo].saida > p->dados[p->topo].chegada) {
				cont += 5;
				break;
			}
			desempilhar(p);
			cont--;
		}
	}

	checaPossibilidade(cont, vagas);
}

void checaPossibilidade(int cont, int vagas) {
	
/* Essa função vai receber o contador (cont) e o número de vagas da garagem. Caso o valor do cont seja
menor ou igual ao número de vagas, será possível. Caso seja maior, será impossível. */

	//printf("\n%d\n", cont);
	
	if (cont <= vagas) {
		printf("Sim\n");
	} else if (cont > vagas){
		printf("aNo\n");
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