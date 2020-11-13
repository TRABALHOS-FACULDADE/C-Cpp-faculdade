/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 2654
*/

#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    string nome;
    int poder;
    int matou;
    int morreu;
} DEUSES;

DEUSES criar_deus(string &nome, int poder, int matou, int morreu) {
    DEUSES d;
    d.nome = nome;
    d.poder = poder;
    d.matou = matou;
    d.morreu = morreu;
    return d;
}

void printVet(vector<DEUSES> &v){
	for (int i=0; i<v.size(); i++) {
        cout << v.at(i).nome << endl;
    }
}

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

void bubbleSort(vector<DEUSES> &deuses) {
    DEUSES aux;

    int len = deuses.size();

    int i, j, trocou = 1;
    for (i = 0; i < len-1 && trocou; i++){
        trocou = 0;
        for (j = 0; j < len-1-i; j++){
            if (deuses.at(j).poder < deuses.at(j+1).poder) {
                //cout << endl << deuses.at(j).nome << " tem menos poder que " << deuses.at(j+1).nome << endl;
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            } else if ((deuses.at(j).matou < deuses.at(j+1).matou) && (deuses.at(j).poder == deuses.at(j+1).poder)) {
                //cout << endl << deuses.at(j).nome << " matou menos que " << deuses.at(j+1).nome << endl;
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            } else if ((deuses.at(j).morreu > deuses.at(j+1).morreu) && (deuses.at(j).matou == deuses.at(j+1).matou) && (deuses.at(j).poder == deuses.at(j+1).poder)) {
                //cout << endl << deuses.at(j).nome << " morreu mais que " << deuses.at(j+1).nome << endl;
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            } else if (comparaChar(deuses.at(j).nome, deuses.at(j+1).nome) && (deuses.at(j).morreu == deuses.at(j+1).morreu) && (deuses.at(j).matou == deuses.at(j+1).matou) && (deuses.at(j).poder == deuses.at(j+1).poder)) {
                //cout << endl << deuses.at(j).nome << " e menor que " << deuses.at(j+1).nome << endl;
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;      
            }
            //printVet(deuses); cout << endl;
        }
    }
}

int registra_deuses(vector<DEUSES> &vetor, int quantidade) {
    DEUSES d;

    for (int i=0; i<quantidade; i++) {
        cin >> d.nome >> d.poder >> d.matou >> d.morreu;
        d = criar_deus(d.nome, d.poder, d.matou, d.morreu);
        vetor.push_back(d);
    }
}

int main() {

    int quantidade, poder, matou, morreu;
    char nome[MAX];
    DEUSES d;
    vector<DEUSES> vetor; // LISTA de deuses

    cin >> quantidade;
    registra_deuses(vetor, quantidade);
    bubbleSort(vetor); // ordena lista de deuses
    cout << vetor.at(0).nome << endl;

    return 0;
}