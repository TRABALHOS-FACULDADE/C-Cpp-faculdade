#include "filaenc.h"

FILA *fi; // Ponteiro para Ponteira (nó cabeça)

int main(){
	PACIENTE p;
	
	fi = cria_fila();
	
	PACIENTE p1;
	p1.idade = 20;
	strcpy(p1.nome, "Anderson");
	p1.sexo = 'M';
	p1.gravida = 0;
	
	PACIENTE p2;
	p2.idade = 22;
	strcpy(p2.nome, "Ursula");
	p2.sexo = 'F';
	p2.gravida = 1;

	PACIENTE p3;
	p3.idade = 22;
	strcpy(p3.nome, "Daniela");
	p3.sexo = 'F';
	p3.gravida = 0;
			
	enfileira(fi, p1);
	imprime_fila(fi);
	enfileira(fi, p2);
	imprime_fila(fi);
	enfileira(fi, p3);
	imprime_fila(fi);
		
	if(desenfileira(fi, &p)){
		printf("####### Paciente sendo atendido: %s\n", p.nome);
	}
	imprime_fila(fi);
	
	PACIENTE p4;
	p4.idade = 22;
	strcpy(p4.nome, "Ronaldo");
	p4.sexo = 'M';
	p4.gravida = 0;
	
	PACIENTE p5;
	p5.idade = 70;
	strcpy(p5.nome, "Sergio");
	p5.sexo = 'M';
	p5.gravida = 0;
	
	PACIENTE p6;
	p6.idade = 80;
	strcpy(p6.nome, "Lourdes");
	p6.sexo = 'F';
	p6.gravida = 0;
	
	enfileira(fi, p4);
	imprime_fila(fi);
	if(desenfileira(fi, &p)){
		printf("####### Paciente sendo atendido(a): %s\n", p.nome);
	}
	
	enfileira(fi, p5);
	imprime_fila(fi);

	enfileira(fi, p6);
	imprime_fila(fi);
	
	if(desenfileira(fi, &p)){
		printf("####### Paciente sendo atendido(a): %s\n", p.nome);
	}
	imprime_fila(fi);
	
	if(desenfileira(fi, &p)){
		printf("####### Paciente sendo atendido(a): %s\n", p.nome);
	}
	imprime_fila(fi);
	
	if(desenfileira(fi, &p)){
		printf("####### Paciente sendo atendido(a): %s\n", p.nome);
	}
	imprime_fila(fi);	

	if(desenfileira(fi, &p)){
		printf("####### Paciente sendo atendido(a): %s\n", p.nome);
	}
	imprime_fila(fi);	
	return 0;
}