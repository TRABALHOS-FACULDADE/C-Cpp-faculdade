#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

void splitEmpilhado(char frase[MAX]) {

    int len = strlen(frase);

    for (int i=0; i<len; i++) {
        if (frase[i] == ' ') {
            printf("\n");
        } else {
            printf("%c", frase[i]);
        }
    }

}