/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 1062
*/

#include <vector>
#include <iostream>

using namespace std;

void printVet(vector<int> &v){
	for (int i=v.size()-1; i>=0; i--) {
        cout << v.at(i) << endl;
    }
}

int empilha_vagoes_b(vector<int> &trem_b, int vagoes) {
    vector<int> aux;
    int v;
    for (int i=0; i<vagoes; i++) {
        cin >> v;
        if (v == 0) return 0;
        aux.push_back(v);
    }
    for (int j=0; j<vagoes; j++) {
        trem_b.push_back(aux.back());
        aux.pop_back();
    }
    return 1;
}

void cria_trem_a(vector<int> &trem_a, int vagoes) {
    for (int i=vagoes; i>0; i--) {
        trem_a.push_back(i);
    }
}

int verificador(vector<int> &trem_a, vector<int> &trem_b, vector<int> &estacao) {
    int len = trem_a.size();
    while (1) {
        if (trem_b.empty()) return 1;
        if (!trem_a.empty()) {
            if ((trem_a.back() == trem_b.back())) {
                trem_a.pop_back();
                trem_b.pop_back();
            } else {
                if (!estacao.empty()) {
                    if (estacao.back() != trem_b.back()) {
                        estacao.push_back(trem_a.back());
                        trem_a.pop_back();
                    } else {
                        estacao.pop_back();
                        trem_b.pop_back();
                    }
                } else {
                    estacao.push_back(trem_a.back());
                    trem_a.pop_back();
                }
            }
        } else {
            if (estacao.back() == trem_b.back()) {
                estacao.pop_back();
                trem_b.pop_back();
            } else return 0;
        }
    }
}   
    

int main() {

    vector<int> trem_a, trem_b, estacao; // PILHAS de trens
    int vagoes;
    while (1) {
        cin >> vagoes;
        if (vagoes == 0) return 0;
        while (1) {
            if (!empilha_vagoes_b(trem_b, vagoes)) break;
            cria_trem_a(trem_a, vagoes);
            if (verificador(trem_a, trem_b, estacao)) {
                cout << "Yes" << endl;
            } else cout << "No" << endl;
            trem_a.clear(); trem_b.clear(); estacao.clear();
        }
        cout << endl;
    }
    return 0;
}