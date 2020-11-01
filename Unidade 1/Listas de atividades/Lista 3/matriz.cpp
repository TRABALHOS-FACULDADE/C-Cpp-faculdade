#include <stdio.h>
#include <locale.h>
#define max 30

int matriz(int mat[max][max], int linhas, int colunas) {

int i, j;
for(i = 0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		printf("%d ", mat[i][j]);
	}
}
}

int main() {

setlocale(LC_ALL, "portuguese");
int mat[max][max];
int i, j, lin, col;

printf("\nLinhas: "); scanf("%d", &lin);
printf("\nColunas: "); scanf("%d", &col);

printf("\n");
for (i = 0; i<lin; i++){
	for (j = 0; j<col; j++){
		printf("Coordenadas %d %d : ", i, j); scanf("%d", &mat[i][j]);
	}
}
matriz(mat, lin, col); printf("\n");

printf("\nMenores que zero: ");
for (i = 0; i<lin; i++){
	for (j = 0; j<col; j++){
	
	if (mat[i][j] < 0) {
			printf(" %d ", mat[i][j]);
		}
	
	}
}

return 0;
}
