/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 1766
*/

#include <iostream>
#include <vector>
#include <string>
 
using namespace std;

typedef struct rena {
    string nome;
    int peso;
    int idade;
    float altura;
} RENA;

void bubbleSort(vector<RENA> &renas, int n) {
    RENA aux;
    int i, j, trocou = 1;
    for (i = 0; i < n-1 && trocou; i++){
        trocou = 0;
        for (j = 0; j < n-1-i; j++){
            if (renas.at(j).peso > renas.at(j+1).peso) {
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            } else if ((renas.at(j).idade < renas.at(j+1).idade) && (renas.at(j).peso == renas.at(j+1).peso)) {
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            } else if ((renas.at(j).altura < renas.at(j+1).altura) && (renas.at(j).idade == renas.at(j+1).idade)) {
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            } else if ((renas.at(j).nome.compare(renas.at(j+1).nome) < 0) && (renas.at(j).altura == renas.at(j+1).altura)) {
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            }
        }
    }
}

int main() {
 
    vector<RENA> renas;
    RENA rena;
    int tamanho, casos, i, j, total, maxTreno, cont;
    
    cin >> casos;
    cin.ignore();
    for (i = 1; i <= casos; i++){
        
        cin >> total >> maxTreno;
        for (j = 0; j < total; j++) {
            cin >> rena.nome >> rena.peso >> rena.idade >> rena.altura;
            renas.push_back(rena);
            tamanho = renas.size();
            bubbleSort(renas, tamanho);
        }
        
        
        cont = 1;
        cout << "CENARIO {" << i << "}" << endl;
        for (j = tamanho - 1; cont <= maxTreno; j--) {
            cout << cont << " - " << renas.at(j).nome << endl;
            cont++;
        }
        renas.clear();
    }
    
    
 
    return 0;
}