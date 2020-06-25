#include <stdio.h>
#include <locale.h>
#define max 10

bool primo (int num) {
	
int cont, i=1, resultado, divisores=0;
bool resp;

for (cont = 0; cont<=num; cont++) {
	
	resultado = num%i;
	
	if(resultado == 0)
	{
		divisores++;
	}
	i++;
	
}
	
	if (divisores <= 2){
		resp = true;
	} 
	
	else if (divisores > 2){
		resp = false;	
	}
	else if (num == 0) {
		resp = false;
	}
	else if (num < 0){
		resp = false;
	}
	
	return resp;
}

void carregaMatriz(int mat[max][max], int linhas, int colunas){

setlocale(LC_ALL, "portuguese");

int i, j;

printf("\n");

for (i=0; i<linhas; i++){
	for(j=0; j<colunas; j++){
		printf("Coordenada [%d][%d] da matriz: ", i, j); scanf("%d", &mat[i][j]);
	}
}

}

void imprimeMatriz(int mat[max][max], int linhas, int colunas){

int i, j;
	
printf("\n");

for (i=0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		printf("%d ", mat[i][j]);
	}
}

}

int somaPrimoDiagonalPrin(int mat[max][max], int linhas, int colunas){

int i, j, soma=0;

for (i=0; i<linhas; i++){
	for (j=0; j<colunas; j++){
		if(i==j && primo(mat[i][j])){
			soma+=mat[i][j];
		}
	}
}

return soma;

}

int main(){

setlocale(LC_ALL, "portuguese");

int lin, col, mat[max][max];

printf("Linhas: "); scanf("%d", &lin);
printf("Colunas: "); scanf("%d", &col);
carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col);

printf("\n");
printf("\nSoma dos elementos primos na diagonal principal da matriz: %d\n", somaPrimoDiagonalPrin(mat, lin, col));

return 0;
}
