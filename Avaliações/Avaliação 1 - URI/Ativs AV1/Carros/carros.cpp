#include "listas.h"
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#include <string.h>

VEICULO v[MAX];
Lista *l;

void inicia() {
	
	setlocale(LC_ALL, "portuguese");
	l = criarLista();
	
	int quantcar;
	
	printf("Informe a quantidade de carros para registrar: "); scanf("%d", &quantcar);
	for (int i=0; i<quantcar; i++) {
		printf("\nPlaca: "); scanf("%s", v[i].placa);
		printf("Modelo: "); scanf("%s", v[i].modelo);
		printf("Cor: "); scanf("%s", v[i].cor);
		v[i] = criarVeiculo(v[i].placa, v[i].modelo, v[i].cor);
		inserirOrdenado(l, v[i]);
	}
	
	imprimirDadosLista(l, v, quantcar);
	printf("\nVeículos ordenados: \n");
	ordenaVeiculos(l, v, quantcar);
}

int main() {
	
	inicia();
	
return 0;
}