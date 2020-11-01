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
	
	if (num < 0){
		resp = false;
	}
	else if (num == 0) {
		resp = false;
	}
	else if (divisores <= 2){
		resp = true;
	} 
	
	else if (divisores > 2){
		resp = false;	
	}
	
	return resp;
}

void carregaVetor(int vet[max], int tam){

setlocale(LC_ALL, "portuguese");

int i;

for(i=0; i<tam; i++){
	printf("\nÍndice %d do vetor: ", i); scanf("%d", &vet[i]);
}
}

void imprimeVetor(int vet[max], int tam){

int i;

printf("\n");
for(i=0; i<tam; i++){
	printf("%d ", vet[i]);
}
}

int somaPrimo(int vet[max], int tam){

int i, soma=0;

for(i=0; i<tam; i++){
	if(primo(vet[i]) == true){
		soma+=vet[i];
	}
}
return soma;
}

int main(){

setlocale(LC_ALL, "portuguese");

int tam, vet[max];

printf("Tamanho do vetor: "); scanf("%d", &tam);
carregaVetor(vet ,tam);
imprimeVetor(vet, tam); printf("\n");

printf("\nSoma dos elementos primos do vetor: %d", somaPrimo(vet, tam));

return 0;
}
