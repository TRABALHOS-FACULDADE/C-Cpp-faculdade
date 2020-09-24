//Referente à questão 06 da lista 3

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
	
	if (divisores <= 2){
		resp = true;
	} 
	
	if (divisores > 2){
		resp = false;	
	}
	
	return resp;
}

int mostraVetor(int tam){

int vet[tam], ind;

for (ind = 0; ind<tam; ind++) {
	printf("\n%dº valor: ", ind+1); scanf("%d", &vet[ind]);
}
printf("\n");
for (ind = 0; ind<tam; ind++) {
	printf("%d ", vet[ind]);
}
	
}

int somaPrimos (int tam){

int ind, vet[tam], soma=0;

for (ind = 0; ind<tam; ind++){
	if(primo(vet[ind]) == true) {
	soma += vet[ind];
	}
}
printf("\nSoma dos elementos primos do vetor: %d ", soma);

}

int main() {

setlocale(LC_ALL, "portuguese");

int tam, ind, vet[tam], soma=0;
	
printf("Digite o tamanho do vetor: "); scanf("%d", &tam);

mostraVetor(tam);
somaPrimos(tam);
	
return 0;	
}
