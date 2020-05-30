#include <stdio.h>
#include <locale.h>

int primos(int num) {

int cont;
int soma=0;
int soma2=0;
int k;
int p;

for (cont=0; cont<=num; cont++) {
	if (cont == 2 || cont == 3 || cont == 5 || cont == 7 || cont == 11 || cont == 13 || cont == 17) {
		printf("\n%d\n", cont);
		soma += cont;
	}
	if (cont%2!=0 && cont%3!=0 && cont%5!=0 && cont%7!=0 && cont%11!=0 && cont%13!=0 && cont%17!=0 && cont%19!=0 && cont%23!=0 && cont%29!=0 && cont%31!=0 && cont%37!=0 && cont%41!=0 && cont%43!=0 && cont%47!=0 && cont%51!=0) {
		printf("\n%d\n", cont);
		soma2 += cont;
	}
}
	return soma + soma2;
}

int main() {

setlocale(LC_ALL, "portuguse");

int x;

scanf("%d", &x);

printf("\nSoma: %d\n", primos(x));

return 0;	

}
