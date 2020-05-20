#include <stdio.h>
#include <locale.h>

int natural (int n) {
	
int soma=0;
int cont;

for(cont=0; cont<n; cont++) {
	
	printf("\n%d\n", cont);

	soma += cont;
	
}
	
	return soma;
}

int main(){

setlocale(LC_ALL, "portuguese");

int x;

printf("Digite um número natural qualquer: ");
scanf("%d", &x);

printf("\n");

printf("Soma: %d", natural(x));

return 0;	

}
