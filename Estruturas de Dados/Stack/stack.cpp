#include <stack>
#include <iostream>

using namespace std;

int main() {
    
    stack<int> pilha;

    pilha.push(1);
    pilha.push(2);
    pilha.push(3);
    pilha.push(4);

    cout << "Topo da pilha: " << pilha.top() << endl;
    cout << "Tamanho: " << pilha.size() << endl;
    cout << "Vazia? " << pilha.empty() << endl; // bool
    pilha.pop();
    cout << "Topo da pilha: " << pilha.top() << endl;

}