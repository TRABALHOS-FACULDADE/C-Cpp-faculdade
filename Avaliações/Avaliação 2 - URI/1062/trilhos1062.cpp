/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 1062
*/

#include <vector>
#include <iostream>
#include <stdio.h>

using namespace std;

typedef struct {
    int value;
} SEQUENCIA;

SEQUENCIA criar_sequencia(int value) {
    SEQUENCIA s;
    s.value = value;
    return s;
}

///////////////////////////////////////////////////////////////////////

// Imprime o vetor
void printVet(vector<SEQUENCIA> &v){
	int i;
    int len = v.size();
	for(i = 0; i<len; i++) {
	}
    cout << endl;
}

// Organiza os elementos
void bubblesort2(vector<SEQUENCIA> &v) {
	int i, j, trocou=1;
    int len = v.size();
    SEQUENCIA aux;
	for (i=0; i<len-1 && trocou; i++) {
		trocou=0; /* inicialmente nenhuma troca foi feita */
		for (j=0; j<len-1-i; j++){
		   if (v.at(j).value > v.at(j+1).value) {
                trocou=1; /* houve troca */
                aux = v.at(j);
                v.at(j) = v.at(j+1);
                v.at(j+1) = aux;
		   }
		}
	}
    printVet(v);
}

///////////////////////////////////////////////////////////////////////

int main() {

    SEQUENCIA s;
    vector<SEQUENCIA> vet;

    scanf("%^[\n", &s.value);
    s = criar_sequencia(s.value);
    vet.push_back(s);
    bubblesort2(vet);

    return 0;
}