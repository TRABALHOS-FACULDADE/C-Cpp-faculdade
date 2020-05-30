#include <stdio.h>
#include <locale.h>
#include <math.h>

int fatorial(int num) {
	
int fat=1;
int cont;

	for (cont=0; cont<num; cont++) {
		
		fat = fat * (cont+1); //fatorial vai multiplicando pelo contador at� chegar ao n�mero estabelecido
		
	}
	return fat;
}

float exponencial(int x, int n) {
	
int contador;
float funcao;
float soma = 0;

for (contador = 0; contador<=n; contador++) { //contador vai fazendo o papel do "n" //contador vai aumentando at� atingir o valor definido para n
	
	funcao = pow(x, contador)/fatorial(contador); //f�rmula exponencial
	
	soma += funcao; //realiza��o do somat�rio da s�rie
	
}
	return soma;
}

int main () {

setlocale(LC_ALL, "portuguese");

int numero;
int expo;

printf("Digite o valor de x para o exponencial: "); scanf("%d", &numero);
printf("\n");
printf("Digite o valor m�ximo de 'n' para fazer o somat�rio da s�rie: "); scanf("%d", &expo);
printf("\n");
printf("\nExponencial: %f\n", exponencial(numero, expo));

return 0;
	
}
