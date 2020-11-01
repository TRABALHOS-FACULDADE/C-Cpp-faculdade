#include <stdio.h>
#include <stdlib.h>
#define MAX 100

char alfabeto[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int gerar_criptografia(char frase[MAX]) {
    FILE *arq_crp = fopen("arq_crp.txt", "w");
    int len_frase = sizeof(frase);
    int len_alfabeto = sizeof(alfabeto);

    for (int i=0; i<len_alfabeto; i++) {
        if (i == 2*len_frase) {
            return 0;
        }
        for (int j=0; j<len_alfabeto; j++) {
            if (frase[i] == alfabeto[j]) {
                if ((j+1) < 10) {
                    fprintf(arq_crp, "0%d", j+1);
                } else {
                    fprintf(arq_crp, "%d", j+1);
                }
            }
        }
    }
    fclose(arq_crp);
}

void gerar_arquivos() {
    char frase[MAX];
    printf("Digite uma frase: ");
    scanf("%s", frase);
    
    FILE *arq = fopen("arq.txt", "w");
    fprintf(arq, "%s", frase);
    fclose(arq);
    gerar_criptografia(frase);
}

int main() {
    gerar_arquivos();
    return 0;
}