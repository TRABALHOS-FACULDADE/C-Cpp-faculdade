#include <stdio.h>
#include <locale.h>

int main() {

setlocale(LC_ALL, "portuguese");

int indice; 
float nota[15] = {2, 7, 8, 7, 10, 9, 7, 8, 5, 6, 5.5, 4.5, 0, 9.5, 8.75};

float soma = 0.0, media;
	
for (indice = 0; indice<15; indice++) {
	
	soma = soma + nota[indice];
	
}

media = soma / 10.0;

printf("\n %0.2f \n", soma);
printf("\n %0.2f \n", media);

return 0;	
	
}
