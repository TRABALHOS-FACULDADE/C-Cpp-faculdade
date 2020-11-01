//referente a questão 15

#include <stdio.h>
#include <locale.h>
#define max 30

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
		if(mat[i][j] < 10 && mat[i][j] > 0) {
			printf("0%d ", mat[i][j]);
		} else {
			printf("%d ", mat[i][j]);
		}
	}
}
}

int somaElementos(int mat[max][max], int linhas, int colunas) {
//soma os elementos localizados na diagonal principal e os elementos que estão abaixo dela
int i, j, soma=0;

printf("\n");
for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		if(i == j || i > j) {
			soma+=mat[i][j];
		}
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

printf("Soma dos elementos: %d", somaElementos(mat, lin, col)); printf("\n");

return 0;
}
