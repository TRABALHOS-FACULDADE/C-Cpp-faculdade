/*
Discentes: Amanda Rigaud, Antônio César, Felipe Ribeiro
Docente: Marcos Lapa
Disciplina: Algorítimos e Estruturas de Dados I
Turma: Engenharia de Computação

Código URI: 2633
*/
#include <stdio.h>
#include <string.h>
#include <vector>

using namespace std;

typedef struct {
    char nome_carne[17];
    int data_validade;
} CARNE;

CARNE criar_carne(char *nome_carne, int data_validade) {
    CARNE c;
    strcpy(c.nome_carne, nome_carne);
    c.data_validade = data_validade;
    return c;
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Imprime o vetor
void printVet(vector<CARNE> &v){
	int i;
    int len = v.size();
	for(i = 0; i<len; i++) {
        if (i==len-1) {
            printf("%s", v.at(i).nome_carne);
        }
        else printf("%s ", v.at(i).nome_carne);
	}
	printf("\n");
}

// Organiza os elementos baseando-se na data de validade
void bubblesort2(vector<CARNE> &v) {
	int i, j, trocou=1;
    CARNE aux;
    int len = v.size();
	for (i=0; i<len-1 && trocou; i++) {
		trocou=0; /* inicialmente nenhuma troca foi feita */
		for (j=0; j<len-1-i; j++){
		   if (v.at(j).data_validade > v.at(j+1).data_validade) {
			trocou=1; /* houve troca */
			aux = v.at(j);
			v.at(j) = v.at(j+1);
			v.at(j+1) = aux;
		   }
		}
	}
    printVet(v);
}

///////////////////////////////////////////////////////////////////////////////////////////////

// Gera a ordem das carnes depois de serem organizadas
int ordem_carnes(int casos) {
    vector<CARNE> vetor;
    CARNE c;
    for (int i=0; i<casos; i++) {
        scanf("%s %d", c.nome_carne, &c.data_validade);
        if (c.data_validade >= 0 && c.data_validade <= 50) {
            c = criar_carne(c.nome_carne, c.data_validade);
            vetor.push_back(c);
        } else return 0;
    }
    bubblesort2(vetor);
    vetor.clear();
}

int main() {
    int casos;
    while(1) {
        while (EOF) {
            scanf("%d", &casos);
            if (casos >= 0 && casos <= 10) {
                ordem_carnes(casos);
            } else return 0;
        }
    }
}