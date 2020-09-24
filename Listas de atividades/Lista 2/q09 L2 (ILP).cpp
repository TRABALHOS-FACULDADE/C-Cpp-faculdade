#include <stdio.h>
#include <locale.h>

bool perfeito(int num) {
	
int cont;
int soma=0;
int divisores;

for (cont = 1; cont<num; cont++) {
	
	divisores = num%cont;
	if (divisores == 0) {
		
		printf("\n%d\n", cont);
		
		soma += cont;
		
	}
}
	
	printf("\nSoma: %d\n", soma);
	
	if (soma==num) {
		return printf("\n%d é perfeito!", num);
	}
	if(soma!=num){
		return printf("\n%d não é perfeito!", num);
	}
}

int main() {

setlocale(LC_ALL, "portuguese");

int x;

printf("Digite um número natural qualquer: ");
scanf("%d", &x);

printf("\n");

printf("\n%\n", perfeito(x));

return 0;
	
} 
