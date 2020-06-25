#include <stdio.h>
#include <locale.h>
#define max 20

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
		if (mat[i][j] < 10 && mat[i][j] > 0){
			printf("0%d ", mat[i][j]);
		} else {
			printf("%d ", mat[i][j]);
	}
	}
}
}

void somaMatrizes(int mat[max][max], int mat2[max][max], int linhas, int colunas){

int i, j, soma[max][max];

printf("\n");
for(i=0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		soma[i][j] = mat[i][j] + mat2[i][j];
	}
}
imprimeMatriz(soma, linhas, colunas);
}

int main(){

setlocale(LC_ALL, "portuguese");

int lin, col, mat[max][max], mat2[max][max];	

printf("Linhas: "); scanf("%d", &lin);
printf("\nColunas: "); scanf("%d", &col);
carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col);
printf("\n");
carregaMatriz(mat2, lin, col);
imprimeMatriz(mat2, lin, col);
printf("\n");
somaMatrizes(mat, mat2, lin, col);

return 0;
}
