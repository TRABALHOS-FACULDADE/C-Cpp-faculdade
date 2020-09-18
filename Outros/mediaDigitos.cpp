#include <stdio.h>
#include <math.h>
#include <locale.h>

float media(int num) {


int primeiros;
int ultimos;
int meio;
int cont;
float k=0;
float soma=0;
float mean;
int n=1;
int pot;

for (n; n<=n+1; n++) {
	
	if (num >= 10 && num < 100) {
	return num;
}
	
	if (num >= (pow(10, n)) && num < (pow(10, n+1))) {
		
		pot  = pow(10, n);
		primeiros = num / (pow(10, n-1));
		meio = num % pot;
		ultimos = meio%100;
		
		
		
		for (cont = primeiros+1; cont<ultimos; cont++) {
		
	k++;
	printf("\n%d\n", cont);
	soma += cont; 
	
}

		for (cont = primeiros-1; cont>ultimos; cont--) {
		
	k++;
	printf("\n%d\n", cont);
	soma += cont; 
	
}

if (primeiros == ultimos) {
	return 0;
}
if (primeiros == ultimos+1 || primeiros+1 == ultimos) {
	return primeiros;
}

	mean = soma/k;
	return mean;
		
	}

}

}

int main() {

int x;

scanf("%d", &x);
printf("\n%f", media(x));
	
	
return 0;
} 
