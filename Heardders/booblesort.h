#include <string.h>
#include <stdio.h>
#define MAX 30

void ordenaStrings(nome[MAX]) { //// Booble sort

char aux[MAX];
int r;

for (int i=MAX; i>=0; i--){
	for (int j=1; j<=i; j++){
		r = strcmp(nome[j-1], nome[j]);
		if (r == 1){
			aux = nome[j-1];
			nome[j-1] = nome[j];
			nome[j] = aux;
		}
	}
}
}