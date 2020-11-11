/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 2654
*/

#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctype.h>
#define MAX 100

using namespace std;

typedef struct {
    char nome[MAX];
    int poder;
    int matou;
    int morreu;
} DEUSES;

DEUSES criar_deus(char *nome, int poder, int matou, int morreu) {
    DEUSES d;
    strcpy(d.nome, nome);
    d.poder = poder;
    d.matou = matou;
    d.morreu = morreu;
    return d;
}


void ordemAlfabetica(vector<DEUSES> &d) {

    char aux[50];
    int r;
    int len_d = d.size();

	for (int i=0; i<len_d; i++) {
		for (int j=i+1; j<len_d; j++) {
			r = strcmp(d.at(i).nome, d.at(j).nome);
			if (r > 0) {
				strcpy(aux, d.at(i).nome);
				strcpy(d.at(i).nome, d.at(j).nome);
				strcpy(d.at(j).nome, aux);
			}
		}
	}
}

void printVet(vector<DEUSES> &v){
	cout << v.at(0).nome;
}

void bubbleSort(vector<DEUSES> &deuses) {
    DEUSES aux;

    int len = deuses.size();

    int i, j, trocou = 1;
    for (i = 0; i < len-1 && trocou; i++){
        trocou = 0;
        for (j = 0; j < len-1-i; j++){
            if (deuses.at(j).poder < deuses.at(j+1).poder) {
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            } else if ((deuses.at(j).matou < deuses.at(j+1).matou)) {
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            } else if ((deuses.at(j).morreu > deuses.at(j+1).morreu)) {
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            } else if (strcmp(deuses.at(j).nome, deuses.at(j+1).nome) < 0 && (isupper(deuses.at(j).nome[0]) && isupper(deuses.at(j+1).nome[0]))) {
                trocou = 1;
                aux = deuses.at(j);
                deuses.at(j) = deuses.at(j+1);
                deuses.at(j+1) = aux;
            }
        }
    }
    printVet(deuses);
}

int registra_deuses(vector<DEUSES> &vetor, int quantidade) {
    DEUSES d;

    for (int i=0; i<quantidade; i++) {
        cin >> d.nome >> d.poder >> d.matou >> d.morreu;
        if ((strlen(d.nome) >= 0 && strlen(d.nome) <= 100) && (d.poder >= 0 && d.poder <=100) && (d.matou >= 0 && d.matou <=100) && (d.morreu >= 0 && d.morreu <=100) ) {
            d = criar_deus(d.nome, d.poder, d.matou, d.morreu);
        } else return 0;
        vetor.push_back(d);
    }
}

int main() {

    int quantidade, poder, matou, morreu;
    char nome[MAX];
    DEUSES d;
    vector<DEUSES> vetor;

    cin >> quantidade;
    if (quantidade >= 1 && quantidade <= 100) {
        registra_deuses(vetor, quantidade);
    }
    bubbleSort(vetor);

    return 0;
}

/*
5
Kratos 70 12 2
Goku 80 0 3
Kuririn 15 0 4
Saitama 100 0 0
Hulk 90 0 0
*/

/*
6
Kratos 70 12 2
Goku 80 0 3
Kuririn 15 0 4
Saitama 100 0 0
Hulk 90 0 0
Yamcha 10 0 0
*/