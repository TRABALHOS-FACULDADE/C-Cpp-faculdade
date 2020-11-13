/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I
Turma: Engenharia de Computação

Código URI: 2633
*/
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

typedef struct {
    string nome;
    int data_validade;
} CARNE;

CARNE criar_carne(string nome, int data_validade) {
    CARNE c;
    c.nome = nome;
    c.data_validade = data_validade;
    return c;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Imprime o vetor
void printVet(vector<CARNE> &v) {
    int len = v.size();
	for(int i = 0; i<len; i++) {
        if (i==len-1) {
            cout << v.at(i).nome;
        }
        else cout << v.at(i).nome << " ";
	}
	printf("\n");
}

// Ordena baseado na data de validade
void quickSort(vector<CARNE> &vetor, int inicio, int fim) {
    int i, j, meio;
    int pivo;
    CARNE aux;
    i = inicio;
    j = fim;
    meio = (int)((i + j) / 2);
    pivo = vetor.at(meio).data_validade;

    do {
        while (vetor.at(i).data_validade < pivo)
            i = i + 1;
        while (vetor.at(j).data_validade > pivo)
            j = j - 1;

        if (i <= j) {
            aux = vetor.at(i);
            vetor.at(i) = vetor.at(j);
            vetor[j] = aux;
            i = i + 1;
            j = j - 1;
        }
    } while (j > i);

    if (inicio < j)
        quickSort(vetor, inicio, j);
    if (i < fim)
        quickSort(vetor, i, fim);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Gera a ordem das carnes depois de serem organizadas
int ordem_carnes(int casos) {
    vector<CARNE> vetor; // LISTA de carnes
    CARNE c;
    for (int i=0; i<casos; i++) {
        cin >> c.nome >> c.data_validade;
        if (c.data_validade >= 0 && c.data_validade <= 50) {
            c = criar_carne(c.nome, c.data_validade);
            vetor.push_back(c);
        } else return 0;
    }
    quickSort(vetor, 0, vetor.size()-1); // organiza a lista de carnes
    printVet(vetor);
    vetor.clear();
}

int main() {
    int casos;
    while (scanf("%d", &casos) != EOF) {
        ordem_carnes(casos);
    }
    return 0;
}