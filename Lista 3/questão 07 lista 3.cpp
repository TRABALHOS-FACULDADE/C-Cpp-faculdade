#include <stdio.h>
#include <locale.h>
#define max 100

bool primo (int num) { //fun��o que garante se o valor � primo ou n�o
	
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

void carregaVetor(int vet[max], int tam){ //fun��o que carrega o vetor

int ind;

for(ind = 0; ind<tam; ind++){
	printf("\n%d� valor: ", ind+1); scanf("%d", &vet[ind]);
}

}

void somaNoIndicePrimo(int vet[max], int tam) { //fun��o para somar os valores que est�o nos �ndices primos do vetor

setlocale(LC_ALL, "portuguese");

int ind, soma=0;

for(ind = 0; ind<tam; ind++){
	if(primo(ind) == true){
		soma += vet[ind];
		if(primo(ind) == false){
			soma -= vet[ind];
		}
	}
}
	printf("\nSoma dos valores nos �ndices primos: %d", soma);
	
}

void imprimeVetor(int vet[max], int tam){ //fun��o que mostra o vetor

int ind;
	
for (ind = 0; ind<tam; ind++){
	printf("%d ", vet[ind]);
}

}

int main() {

setlocale(LC_ALL, "portuguese");

int num, tam, ind;
int vet[tam];	

printf("Digite o tamanho do vetor: "); scanf("%d", &tam);

carregaVetor(vet, tam);
printf("\n"); imprimeVetor(vet, tam);
printf("\n"); somaNoIndicePrimo(vet, tam);

return 0;
}
