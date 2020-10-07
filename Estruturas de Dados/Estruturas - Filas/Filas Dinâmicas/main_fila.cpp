#include "filaencadeada.cpp"
#include <vector>
#include <iostream>
#include <locale.h>
#define MAX 100

using namespace std;
FILA *f;
PACIENTE p;

PACIENTE adicionaPacientes(int pacientes, FILA *f) {
    for (int i=0; i<pacientes; i++) {
        cout << "Nome: "; cin >> p.nome;
        cout << "Idade: "; cin >> p.idade;
        cout << "Gravida? (0 -> Nao // 1 -> Sim) "; cin >> p.gravida;
        p = criarPaciente(p.nome, p.idade, p.gravida);
        enfileira(f, p);
    }
}


int main() {

    setlocale(LC_ALL, "portuguese");

    f = cria_fila();

    int pacientes;
    cout << "Quantos pacientes? "; cin >> pacientes;
    adicionaPacientes(pacientes, f);
    imprimePaciente(pacientes, f);

    return 0;
}