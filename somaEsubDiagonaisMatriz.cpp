#include <stdio.h>
#include <locale.h>
#define max 10

void carregaMatriz(int mat[max][max], int ordem){

setlocale(LC_ALL, "portuguese");

int i, j;

for(i=0; i<ordem; i++){
	for(j=0; j<ordem; j++){
		printf("\nCoordenadas [%d][%d] da matriz: ", i, j); scanf("%d", &mat[i][j]);
	}
}
}

void imprimeMatriz(int mat[max][max], int ordem){

int i, j;

printf("\n");
for(i=0; i<ordem; i++){
	printf("\n");
	for(j=0; j<ordem; j++){
		if(mat[i][j] < 10 && mat[i][j] > 0){
			printf("0%d ", mat[i][j]);
		} else{
			printf("%d ", mat[i][j]);
		}
	}
}
}

void somaDiagonaisPrinSec(int mat[max][max], int mat2[max][max], int ordem){

int i, j, soma[max][max];

printf("\n");
for(i=0; i<ordem; i++){
	for(j=0; j<ordem; j++){
		if(i==j){
			soma[i][j] = mat[i][j] + mat2[i][j];
		}
		if(i!=j){
			soma[i][j] = mat[i][j] - mat2[i][j];
		}
	}
}
imprimeMatriz(soma, ordem);
}

int main(){

setlocale(LC_ALL, "portuguese");

int mat[max][max], mat2[max][max], ordem;

printf("Ordem da matriz quadrada: "); scanf("%d", &ordem);
printf("\n");
carregaMatriz(mat, ordem);
imprimeMatriz(mat, ordem);
printf("\n");
carregaMatriz(mat2, ordem);
imprimeMatriz(mat2, ordem);

somaDiagonaisPrinSec(mat, mat2, ordem);

return 0;
}
