//referente a questão 9

#include <stdio.h>
#include <locale.h>
#define max 10

void carregaMatriz(int mat[max][max], int linhas, int colunas) {

int i, j;

printf("\n");
for (i = 0; i<linhas; i++){
	for (j = 0; j<colunas; j++){
		printf("Coordenadas %d %d : ", i, j); scanf("%d", &mat[i][j]);
	}
}	
	
}

void matriz(int mat[max][max], int linhas, int colunas) {

int i, j;
for(i = 0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		printf("%d ", mat[i][j]);
	}
}
}

int somaLinhas(int mat[max][max], int linhas, int colunas){
		
int i, j, sumLin=0; //sumLin é para armazenar a soma das linhas

for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++) {
		sumLin+=mat[i][j];
}
printf("\nSoma da %dª linha: %d", i+1, sumLin);
sumLin = 0;
}
}

int somaTotal(int mat[max][max], int linhas, int colunas) {

int i, j, soma=0;

printf("\n");
for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		soma+=mat[i][j];
	}
}
	return soma;	
}

int main() {

setlocale(LC_ALL, "portuguese");
int mat[max][max];
int i, j, lin, col;

printf("\nLinhas: "); scanf("%d", &lin);
printf("\nColunas: "); scanf("%d", &col);

carregaMatriz(mat, lin, col); printf("\n");
matriz(mat, lin, col); printf("\n");

somaLinhas(mat, lin, col);

printf("\nSoma de todos os elementos: %d", somaTotal(mat, lin, col));

return 0;
}
