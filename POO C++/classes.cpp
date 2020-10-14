#include <iostream>
#define MAX 30

using namespace std;

class Pessoa {

    public:
        char nome[MAX];
        char sobrenome[MAX];
        char sexo[10];
        int idade;

    private:
        char cpf[20];
};

int main() {

    Pessoa p;

    cout << "Nome completo: "; cin >> p.nome >> p.sobrenome;
    cout << "Idade: "; cin >> p.idade;
    cout << "Sexo: "; cin >> p.sexo;
    cout << p.nome << " " << p.sobrenome << endl << p.idade << endl << p.sexo << endl;
    

    return 0;
}