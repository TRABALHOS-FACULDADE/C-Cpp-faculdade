/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I

Código URI: 2654
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
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

int main() {

    int quantidade, poder, matou, morreu;
    char nome[MAX];
    DEUSES d;
    vector<DEUSES> vetor, *ptr_vet;
    ptr_vet = &vetor;

    scanf("%d", &quantidade);
    for (int i=0; i<quantidade; i++) {
        scanf("%s %d %d %d", d.nome, &d.poder, &d.matou, &d.morreu);
        d = criar_deus(d.nome, d.poder, d.matou, d.morreu);
        vetor.push_back(d);
    }

}