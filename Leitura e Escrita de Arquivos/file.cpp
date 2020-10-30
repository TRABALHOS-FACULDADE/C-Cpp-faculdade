#include <stdio.h>
#include <stdlib.h>


typedef struct {
    char nome[100];
    int idade;
}Pessoa;

int main() {

    Pessoa p;
    printf("Digite seu nome: ");
    fflush(stdin);
    gets(p.nome);

    printf("\nDigite sua idade: ");
    scanf("%d", &p.idade);

    FILE *arq = fopen("new_archive.txt", "w");
    fprintf(arq, "Nome: %s\nIdade: %d\n", p.nome, p.idade);

    fclose(arq);
}
