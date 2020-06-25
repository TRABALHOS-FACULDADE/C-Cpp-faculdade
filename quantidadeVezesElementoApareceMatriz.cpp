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

int identificaElemento(int mat[max][max], int linhas, int colunas, int elemento){

int i, j, cont=0;

for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		if(mat[i][j] == elemento){
			cont++;
		}
	}
}
return cont;
}

void contaElementos(int mat[max][max], int linhas, int colunas, int elemento){

int i, j, cont=0;

for(i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		if(mat[i][j] == elemento){
			cont++;
		}
	}
}

if (cont == 1) {
	printf("\nO número %d aparece %d vez!", elemento, identificaElemento(mat, linhas, colunas, elemento));	
} else if (cont == 0) {
	printf("\nO número %d não aparece nenhuma vez!", elemento, identificaElemento(mat, linhas, colunas, elemento));
} else {
	printf("\nO número %d aparece %d vezes!", elemento, identificaElemento(mat, linhas, colunas, elemento));
}
}

int main(){

setlocale(LC_ALL, "portuguese");

int i, j, lin, col, mat[max][max], numE;

printf("Linhas: "); scanf("%d", &lin);
printf("Colunas: "); scanf("%d", &col);
carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col); printf("\n");

printf("\nQual número deseja saber quantas vezes aparece na matriz? "); scanf("%d", &numE);
contaElementos(mat, lin, col, numE);

return 0;
}
