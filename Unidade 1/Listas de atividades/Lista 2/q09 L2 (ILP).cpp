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
		return printf("\n%d � perfeito!", num);
	}
	if(soma!=num){
		return printf("\n%d n�o � perfeito!", num);
	}
}

int main() {

setlocale(LC_ALL, "portuguese");

int x;

printf("Digite um n�mero natural qualquer: ");
scanf("%d", &x);

printf("\n");

printf("\n%\n", perfeito(x));

return 0;
	
} 
