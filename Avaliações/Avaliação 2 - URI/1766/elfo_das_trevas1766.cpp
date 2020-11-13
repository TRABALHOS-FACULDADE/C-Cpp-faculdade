/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 1766
*/

#include <iostream>
#include <vector>
#include <string.h>
 
using namespace std;

typedef struct rena {
    string nome;
    int peso;
    int idade;
    float altura;
} RENA;

int comparaChar(string a, string b) {
    int menor;
    a.length() < b.length() ? menor = a.length() : menor = b.length();
    for (int k=0; k<menor; k++) {
        if (a.at(k) > b.at(k)) {
            return 1;
        } else if (b.at(k) > a.at(k)) return 0;
    }
    return 1;
}

void bubbleSort(vector<RENA> &renas) {
    RENA aux;

    int len = renas.size();

    int i, j, trocou = 1;
    for (i = 0; i < len-1 && trocou; i++){
        trocou = 0;
        for (j = 0; j < len-1-i; j++){
            if (renas.at(j).peso > renas.at(j+1).peso) {
                //cout << endl << renas.at(j).nome << " tem menos peso que " << renas.at(j+1).nome << endl;
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            } else if ((renas.at(j).idade < renas.at(j+1).idade) && (renas.at(j).peso == renas.at(j+1).peso)) {
                //cout << endl << renas.at(j).nome << " idade menos que " << renas.at(j+1).nome << endl;
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            } else if ((renas.at(j).altura < renas.at(j+1).altura) && (renas.at(j).idade == renas.at(j+1).idade) && (renas.at(j).peso == renas.at(j+1).peso)) {
                //cout << endl << renas.at(j).nome << " altura mais que " << renas.at(j+1).nome << endl;
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            } else if (comparaChar(renas.at(j).nome, renas.at(j+1).nome) && (renas.at(j).altura == renas.at(j+1).altura) && (renas.at(j).idade == renas.at(j+1).idade) && (renas.at(j).peso == renas.at(j+1).peso)) {
                //cout << endl << renas.at(j).nome << " e menor que " << renas.at(j+1).nome << endl;
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;      
            }
            //printVet(renas); cout << endl;
        }
    }
}

int resultado(vector<RENA> &renas, int maxTreno, int i) {
    int cont = 1;
    int len = renas.size();
    int j;
    cout << "CENARIO {" << i << "}" << endl;
    for (j = len - 1; cont <= maxTreno; j--) {
        cout << cont << " - " << renas.at(j).nome << endl;
        cont++;
    }
}

int main() {
 
    vector<RENA> renas; // LISTA de renas
    RENA rena;
    int tamanho, casos, i, j, total, maxTreno;
    
    cin >> casos;
    for (i = 1; i <= casos; i++){
        cin >> total >> maxTreno;
        for (j = 0; j < total; j++) {
            cin >> rena.nome >> rena.peso >> rena.idade >> rena.altura;
            renas.push_back(rena);
            bubbleSort(renas); // ordena lista de renas
        }
        resultado(renas, maxTreno, i);
        renas.clear();
    }
    return 0;
}