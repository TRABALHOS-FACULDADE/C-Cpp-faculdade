#include <iostream>
#include <stdio.h>

using namespace std;

void calculaMedia(int nota1, int nota2) {
    float media = (nota1+nota2)/2;
    printf("%.1f", media);
}

int main() {
    int nota1, nota2; cin >> nota1 >> nota2;
    if (nota1 < 0 || nota2 < 0) {
        cout << "Por favor, informe numeros positivos." << endl; return 0;
    }
    calculaMedia(nota1, nota2);
    return 0;
} 