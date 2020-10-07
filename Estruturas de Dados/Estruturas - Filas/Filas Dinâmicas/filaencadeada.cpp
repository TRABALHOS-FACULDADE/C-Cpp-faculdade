#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

typedef struct{
    char nome[150];
    int idade;
    char sexo;
    short gravida; //// 0 = não //1 = sim
} PACIENTE;

PACIENTE criarPaciente(char* nome, int idade, short gravida) {
    PACIENTE p;
    strcpy(p.nome, nome);
    p.idade = idade;
    p.gravida = gravida;
    return p;
}

typedef struct no{
    PACIENTE dados;
    struct no *prox;
} NO;
typedef struct{
    NO *ini;
    NO *fim;
}FILA;

FILA* cria_fila(){
    FILA *fi = (FILA*) malloc(sizeof(FILA));
    if(fi != NULL){ // Deu certo a alocação
        fi->fim = NULL;
        fi->ini = NULL;
    }
    return fi;
}


int fila_vazia(FILA *f){
    if(f==NULL || f->ini==NULL) return 1;
    return 0;
}

int enfileira(FILA *f, PACIENTE p){
    if(f==NULL) return 0;
    NO *novo_no = (NO*)malloc(sizeof(NO));
    if(novo_no == NULL) return 0;
        novo_no->dados = p;
        novo_no->prox = NULL;
    if(f->ini == NULL){ // Fila vazia, inserir no início
        f->ini = novo_no;
        f->fim = novo_no;
    }else{
        f->fim->prox = novo_no;
        f->fim = novo_no;
    }
    return 1;
}

int desenfileira(FILA *f, PACIENTE *p){
    if(fila_vazia(f)) return 0;
    NO *aux = f->ini;
    strcpy(p->nome, aux->dados.nome);
    p->idade = aux->dados.idade;
    p->sexo = aux->dados.sexo;
    p->gravida = aux->dados.gravida;
    // Desloca o inicio fazendo-o apontar para o próximo nó
    f->ini = aux->prox;
    free(aux); // Libera o nó desempilhado
    return 1;
}

void imprimePaciente(int pacientes, FILA*f) {
    NO *aux = f->ini;
    cout << endl;
    for (int i=0; i<pacientes; i++) {
        cout << "===== Paciente " << i+1 << " =====" << endl;
        cout << aux->dados.nome << endl;
        cout << aux->dados.idade << endl;
        if (aux->dados.gravida == 0) cout << "Gravida? Nao\n";
        else cout << "Gravida: Sim\n";
    }
}