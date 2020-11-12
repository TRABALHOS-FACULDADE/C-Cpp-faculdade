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
    char nome[100];
    int peso;
    int idade;
    float altura;
} RENA;

RENA criar_rena(char *nome, int peso, int idade, float altura) {
    RENA r;
    strcpy(r.nome, nome);
    r.peso = peso;
    r.idade = idade;
    r.altura = altura;
    return r;
}

void bubbleSort(vector<RENA> &renas) {
    RENA aux;
    int i, j, trocou = 1;
    int len = renas.size();
    for (i = 0; i < len-1 && trocou; i++){
        trocou = 0;
        for (j = 0; j < len-1-i; j++){
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
            } else if ((strcmp(renas.at(j).nome, renas.at(j+1).nome) < 0) && (renas.at(j).altura == renas.at(j+1).altura)) {
                trocou = 1;
                aux = renas.at(j);
                renas.at(j) = renas.at(j+1);
                renas.at(j+1) = aux;
            }
        }
    }
}

int registra_rena(vector<RENA> &renas) {

    RENA rena;
    int tamanho, casos, i, j, total, maxTreno, cont;

    for (i = 1; i <= casos; i++){
        cin >> total >> maxTreno;
        if ((total >= 5) && (maxTreno <= 1000)) {
            for (j = 0; j < total; j++) {
                cin >> rena.nome >> rena.peso >> rena.idade >> rena.altura;
                if ((rena.peso >= 1 && rena.peso <= 300) && (rena.idade >= 1 && rena.idade <= 300) && (rena.altura >= 0.0 && rena.altura <= 3.00)) {
                    renas.push_back(rena);
                    tamanho = renas.size();
                    bubbleSort(renas);
                } else return 0;
            }
            cont = 1;
            cout << "CENARIO {" << i << "}" << endl;
            for (j = tamanho - 1; cont <= maxTreno; j--) {
                cout << cont << " - " << renas.at(j).nome << endl;
                cont++;
            }
            renas.clear();
        } else return 0;
    }
}

int main() {
 
    vector<RENA> renas;
    RENA rena;
    int tamanho, casos, i, j, total, maxTreno, cont;
    
    cin >> casos;
    cin.ignore();
    if (casos >= 1 && casos <= 100000) {
        registra_rena(renas);
    }
    return 0;
}

/*
1
9 5
Rudolph 50 100 1.12
Dasher 10 121 1.98
Dancer 10 131 1.14
Prancer 7 142 1.36
Vixen 50 110 1.42
Comet 50 121 1.21
Cupid 50 107 1.45
Donner 30 106 1.23
Blitzen 50 180 1.84
*/