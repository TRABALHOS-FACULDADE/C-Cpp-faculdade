/* Desafio 1259 - Pares e Ímpares */

#include <iostream>
#include <vector>
#include <locale.h>
#include <algorithm>

using namespace std;

void printVector(vector<int> v, vector<int>v2) {
    for (int i=0; i<v.size(); i++) {
    cout << v[i] << endl; 
}
    for (int i=v2.size()-1; i>=0; i--) {
    cout << v2[i] << endl; 
}
}

int main() {

    int quantidade; cin >> quantidade;

    vector<int>v;
    vector<int>v2;
    int valor;

    for (int i=0; i<quantidade; i++) {
        cin >> valor;
        if (valor%2 == 0) {
            v.push_back(valor);
        } else if (valor%2 != 0) {
            v2.push_back(valor);
        }
    }

    std::sort(v.begin(), v.end());
    std::sort(v2.begin(), v2.end());
    printVector(v, v2);
}