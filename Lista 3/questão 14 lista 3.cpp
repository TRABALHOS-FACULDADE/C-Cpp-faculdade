#include <stdio.h>
#include <locale.h>
#define max 30

void carregaMatriz(int mat[max][max], int linhas, int colunas) {
	
int i, j;

printf("\n");
for (i = 0; i<linhas; i++){
	for (j = 0; j<colunas; j++){
		printf("Coordenadas [%d] [%d] : ", i, j); scanf("%d", &mat[i][j]);
	}
}
	
}

void imprimeMatriz(int mat[max][max], int linhas, int colunas) {

int i, j;
for(i = 0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		printf("%d ", mat[i][j]);
	}
}
}

void somaDiagonalSec(int mat[max][max], int linhas, int colunas) {

int i, j, soma=0;

for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		if(i+j == linhas-1){
			soma+=mat[i][j];
		}
	}
}
printf("\n");
printf("\nSoma da diagonal secundária: %d", soma);
}

int main() {

setlocale(LC_ALL, "portuguese");
int mat[max][max];
int i, j, lin, col;

printf("Informe uma matriz quadrada!\n");

printf("\nLinhas: "); scanf("%d", &lin);
printf("\nColunas: "); scanf("%d", &col);

if(lin != col){
	printf("\nInforme somente matrizes quadradas!\n");
}

else {
carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col);
somaDiagonalSec(mat, lin, col);
}
return 0;
}
