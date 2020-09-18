#include <stdio.h>
#include <locale.h>
#define max 30

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
	if (num == 0) {
		resp = false;
	}	
	else if (divisores <= 2){
		resp = true;
	}  
	else if (divisores > 2){
		resp = false;	
	}
	else if (num < 0){
		resp = false;
	}
	
	return resp;
}

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

int somaIndicesPrimos(int mat[max][max], int linhas, int colunas) {
//faz a soma dos elementos cuja soma de seus índices dê um valor primo
int i, j, soma=0;
for(i = 0; i<linhas; i++){
	printf("\n");
	for(j=0; j<colunas; j++){
		if(primo(i+j) == true) {
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

carregaMatriz(mat, lin, col);
imprimeMatriz(mat, lin, col);
printf("\nSoma dos elementos nos índices cuja soma é um número primo: %d\n", somaIndicesPrimos(mat, lin, col));


return 0;
}
