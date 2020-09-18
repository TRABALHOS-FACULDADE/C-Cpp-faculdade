#include <stdio.h>
#include <locale.h>
#define max 10

void carregaMatriz(int mat[max][max], int linhas, int colunas){

int i, j;

setlocale(LC_ALL, "portuguese");

printf("\n");
for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		printf("Coordenadas [%d][%d] da matriz: ", i, j); scanf("%d", &mat[i][j]);
	}
}
}

void imprimeMatriz(int mat[max][max], int linhas, int colunas){

int i, j;

printf("\n");
for(i=0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		if(mat[i][j] < 10 && mat[i][j] > 0){
			printf("0%d ", mat[i][j]);
		} else{
			printf("%d ", mat[i][j]);
		}
	}
}
}

void reduzMatriz(int mat[max][max], int linhas, int colunas, int valorLin, int valorCol){

int i, j;

printf("\n");
for(i=0; i<linhas-valorLin; i++){
	printf("\n");
	for(j=0; j<colunas-valorCol; j++){
		if(mat[i][j] < 10 && mat[i][j] > 0){
			printf("0%d ", mat[i][j]);
		} else{
			printf("%d ", mat[i][j]);
		}
	}
}

}

int main(){

setlocale(LC_ALL, "portuguese");

int i, j, lin, col, mat[max][max], valorLin, valorCol, indL;

printf("Linhas: "); scanf("%d", &lin);
printf("Colunas: "); scanf("%d", &col);
carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col); printf("\n");

printf("\nDeseja reduzir quantas linhas da matriz? "); scanf("%d", &valorLin);
printf("\nDeseja reduzir quantas colunas da matriz? "); scanf("%d", &valorCol);

if (valorLin < 0 || valorCol < 0 || valorLin > lin || valorCol > col) {
	printf("\nImpossível realizar operação!");
} else {
	reduzMatriz(mat, lin, col, valorLin, valorCol);
}
return 0;
}
