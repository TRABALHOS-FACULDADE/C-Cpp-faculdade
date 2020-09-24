#include <math.h>
#include <locale.h>
#include <stdio.h>

float fatorial(int num) {
	
int fat=1;
int cont;

	for (cont=0; cont<num; cont++) {
		
		fat = fat * (cont+1); //fatorial vai multiplicando pelo contador até chegar ao número estabelecido
		
	}
	return fat;
}

float cosseno(int x, int k) {
	
float cos;
float contador;
float soma=1;
float pi = 3.14159265;
float radiano = pi/180;
float angulo = x*radiano;

for (contador=1; contador<=k; contador++) { //garantir que  o expoente do numerador e a base do denominador fiquem aumentando
	
	cos = (pow(-1, contador) * pow(angulo, 2*contador)) / fatorial(2*contador); //fórmula expansão do cosseno
	
	soma = soma + cos; //garantir que à medida que o contador for alterando, os valores vão se somando

}

return soma;
	
}

int main () {
	
setlocale(LC_ALL, "portuguese");

int n;
int kn;

	printf("Digite o ângulo que deseje calcular o cosseno: ");
	scanf("%d", &n);
	
	printf("Digite um número natural: ");
	scanf("%d", &kn);
	
	printf("%f", cosseno(n, kn));
	
	return 0;
	
}
