#include <stdio.h>
#include <locale.h>

int main()

{  /* Nesse exemplo, o usu�rio define o tamanho do vetor...*/

setlocale(LC_ALL, "portuguese");

 int ind, tam;
 int menor=0;
  
 printf("\n Qual o tamanho do vetor? ");
 scanf("%d",&tam);
 
/* Declara o vetor depois que souber o tamanho */

 int vet[tam]; 

 for(ind = 0; ind<tam; ind++)
 {  printf("\n Digite o %d� valor:",ind+1);
    scanf("%d",&vet[ind]); }

/* ...que � apresentado na ordem em que foram informados.*/
menor = vet[0];
 for(ind=0;ind<tam;ind++){
    if(vet[ind]<menor){
        menor=vet[ind];
            }
        }
printf("\n O menor valor �: %d", menor);

return 0;
} 


