#include <stdio.h>
#include <locale.h>
#define max 10

void carregaMatriz(int mat[max][max], int linhas, int colunas) {
	
int i, j;

printf("\n");
for (i = 0; i<linhas; i++){
	for (j = 0; j<colunas; j++){
		printf("Coordenadas [%d] [%d] : ", i, j); scanf("%d", &mat[i][j]);
	}
}
	
}

void imprimeMatriz(int mat[max][max], int linhas, int colunas){

int i, j;

for(i=0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		if (mat[i][j]<10 && mat[i][j] > 0){
			printf("0%d ", mat[i][j]);
		} else {
		printf("%d ", mat[i][j]);
	}
	}
}

}

int somaDiagonalPrinc(int mat[max][max], int linhas, int colunas){

int i, j, soma=0;

for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		if(i==j){
			soma+=mat[i][j];
		}
	}
}
return soma;
}

int somaDiagonalSec(int mat[max][max], int linhas, int colunas){

int i, j, soma=0;

for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		if(i+j == linhas-1){
			soma+=mat[i][j];
		}
	}
}
return soma;
}

int main(){

setlocale(LC_ALL, "portuguese");

int i, j, lin, lin2, col, col2, mat[max][max], mat2[max][max];

printf("Informe duas matrizes que sejam quadradas e de mesmo tamanho!\n");
printf("\nLinhas da primeira matriz: "); scanf("%d", &lin);
printf("\nColunas da primeira matriz: "); scanf("%d", &col);

if (lin != col){
	printf("\nInformar apenas matrizes quadradas de mesmo tamanho!\n");
	return 0;
}

carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col); printf("\n");

printf("\nLinhas da segunda matriz: "); scanf("%d", &lin2);
printf("\nColunas da segunda matriz: "); scanf("%d", &col2);

if (lin != lin2 || col != col2){
	printf("\nInformar apenas matrizes quadradas de mesmo tamanho!\n");
	return 0;
}

if (lin2 != col2){
	printf("\nInformar apenas matrizes quadradas de mesmo tamanho!\n");
	return 0;
}

carregaMatriz(mat2, lin, col);
imprimeMatriz(mat2, lin2, col2); printf("\n");

printf("\nSoma da diagonal principal da primeira matriz: %d", somaDiagonalPrinc(mat, lin, col));
printf("\nSoma da diagonal principal da segunda matriz: %d", somaDiagonalPrinc(mat2, lin2, col2));

printf("\nSoma da diagonal secundária da primeira matriz: %d", somaDiagonalSec(mat, lin, col));
printf("\nSoma da diagonal secundária da segunda matriz: %d", somaDiagonalSec(mat2, lin2, col2));

return 0;
}
