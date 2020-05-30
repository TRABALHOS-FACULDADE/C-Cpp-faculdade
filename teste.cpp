#include <stdio.h>
#include <locale.h>

int main() {
	
int indice, nota[5] = {2, 7, 8, 7, 10};

float soma = 0, media;
	
for (indice = 0; indice<5; indice++) {
	
	soma = soma + nota[indice];
	
}

media = soma / 5;

printf("\n%f\n", media);

return 0;	
	
}
