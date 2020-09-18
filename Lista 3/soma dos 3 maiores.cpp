#include <stdio.h>
#include <locale.h>

int soma3maiores(int tam){

int ind, vet[tam], menors, maior, maior2, maior3, soma=0;

for(ind = 0; ind<tam; ind++) {
  printf("\n%dº valor:",ind+1); scanf("%d",&vet[ind]); 
}

maior = vet[0];
for (ind=0; ind<tam; ind++){
	if(vet[ind]>maior){
		maior=vet[ind];
	}
}
printf("\nMaior: %d", maior);

maior2 = vet[0];
for (ind=0; ind<tam; ind++){
	if(vet[ind] < maior && vet[ind] > maior2){
		maior2 = vet[ind];
	}
}

printf("\nMaior 2: %d", maior2);

maior3 = vet[0];
for (ind=0; ind<tam; ind++){
	if(vet[ind] < maior2 && vet[ind] > maior3){
		maior3 = vet[ind];
	}
}

printf("\nMaior 3: %d", maior3);

	soma = maior + maior2 + maior3;
	return soma;
}

int main() {
	
int tamanho; setlocale(LC_ALL, "portuguese");

printf("Qual é o tamanho do vetor? "); scanf("%d", &tamanho);

if (tamanho < 3){
	printf("\nImpossível somar valores deste vetor com menos de 3 elementos!\n");
} else {
printf("\nSoma: %d\n", soma3maiores(tamanho));
}	

return 0;
}
