#include <vector>
#include <iostream>
#include <locale.h>

using namespace std;

void printVector(vector<int> v) {
    for (int i=0; i<v.size(); i++) {
    cout << v[i] << ' ';
}
}

void multiPush(vector<int>v) {
    int tam, valor;

    cout << "\nTamanho do vetor: "; cin >> tam;
    for (int i=0; i<tam; i++) {
        cout << "Indice " << "[" << i << "] "; cin >> valor;
        v.push_back(valor);
    }

    printVector(v);
}

int main() {
    setlocale(LC_ALL, "portuguese");
    vector<int>v;

    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    printVector(v);

    v.pop_back(); cout << "\n";

    printVector(v);

    v.erase(v.end() - 2); cout << "\n";
    printVector(v);

    cout << "\n" << "Tamanho da array: " << v.size();

    multiPush(v);
}