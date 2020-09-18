#include <string.h>
#include <stdio.h>
int const MAX = 100;

void BoobleSort(char palavra[][MAX], int quant) {

int r;
char aux[MAX];

for (int i=0; i<quant-1; i++) { 
        for (int j=i+1; j<quant; j++) { 
            if (strcmp(palavra[i], palavra[j]) > 0) { 
                strcpy(aux, palavra[i]); 
                strcpy(palavra[i], palavra[j]); 
                strcpy(palavra[j], aux); 
            }
        }
    }
}
