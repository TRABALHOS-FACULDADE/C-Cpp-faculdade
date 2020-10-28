#include <list>
#include <iostream>

using namespace std;

int main() {

    list<int> lista;
    lista.push_front(33);
    lista.push_front(2);
    lista.push_front(3);
    lista.push_front(42);

    cout << lista.empty() << ' '; // bool (0 e 1)
    cout << lista.size() << ' '; // tamanho
    cout << lista.front() << ' '; // elemento do topo
    cout << lista.back() << ' '; // elemento da base
    
    cout << "\n";

    for (int i=0; i<5; i++) {
        lista.push_front(i*2);
    }
    cout << lista.empty() << ' '; // bool (0 e 1)
    cout << lista.size() << ' '; // tamanho
    cout << lista.front() << ' '; // elemento do topo
    cout << lista.back() << ' '; // elemento da base

}