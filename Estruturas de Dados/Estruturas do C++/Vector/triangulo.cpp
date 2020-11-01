#include <vector>
#include <iostream>
#include <locale.h>

using namespace std;

void printVector(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
    cout << v[i] << ' ' ;
}
}

void multiPush(vector<int>v) {
    int tam, valor;

    cout << "\nTamanho do vetor: "; cin >> tam;
    for (int i=0; i<tam; i++) {
        cout << "Indice " << "[" << i << "] "; cin >> valor;
        v.push_back(valor);
    }

    for (int k=tam-1; k>=0; k--) { /* Gera o triângulo */
        v.erase(v.end() - 1);
        printVector(v);
        cout << "\n";
    }

}

int main() {
    vector<int>v;

    multiPush(v);
}