//Referente à questão 08 da lista 3

#include <stdio.h>
#include <locale.h>
#define max 30

void ordenaVetor(int tam){

int ind, vet[tam], j, aux;

for(ind = 0; ind<tam; ind++) {
  printf("\n%dº valor: ",ind+1); scanf("%d", &vet[ind]); 
}

printf("\nVetor em ordem decrescente: ");
for(ind = 0; ind<tam; ind++){
	for(j=ind; j<tam; j++){
		if(vet[ind] < vet[j]){
			aux = vet[ind];
			vet[ind] = vet[j];
			vet[j] = aux;
		}
	}
	printf("%d ", vet[ind]);
}

}

int main() {
	
setlocale(LC_ALL, "portuguese");

int tamanho, indice;
int vetor[tamanho];
	
printf("Digite o tamanho do vetor: "); scanf("%d", &tamanho);
printf("\n");
ordenaVetor(tamanho);
	
return 0;
}
