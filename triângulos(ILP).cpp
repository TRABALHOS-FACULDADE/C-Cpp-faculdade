#include <stdio.h>
#include <locale.h>

using namespace std;

int main() {
	setlocale(LC_ALL, "");
	float lado1;
	float lado2;
	float lado3;

	printf("Digite o primeiro lado do tri�ngulo: "); scanf("%f", &lado1);
	printf("\n");
	printf("Digite o segundo lado do tri�ngulo: "); scanf("%f", &lado2);
	printf("\n");
	printf("Digite o terceiro lado do tri�ngulo: "); scanf("%f", &lado3);
	printf("\n");

	lado1 < lado2 + lado3;
	lado2 < lado1 + lado3;
	lado3 < lado1 + lado2;

	if (lado1 == lado2 && lado2 == lado3 && lado1 == lado3) {
		printf("Tri�ngulo equil�tero! \n");
	}
	else {
		if (lado1 == lado2) {
			printf("Tri�ngulo is�sceles! \n");
		}
		if (lado2 == lado3) {
			printf("Tri�ngulo is�sceles! \n");
		}
		if (lado1 == lado3) {
			printf("Tri�ngulo is�sceles! \n");
		}
		else {
			if ((lado1 != lado2) && (lado1 != lado3) && (lado2 != lado3)) {
				printf("Tri�ngulo escaleno! \n");
			}
		}
		return 0;
	}
}
