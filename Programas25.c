#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RAM25.h"
#include "CPU25.h"
#include "Programas25.h"

void programaMult(CPU *cpu, int multiplicando, int multiplicador){

    //executar instrucao
	//-1 -> halt
	// 0 -> soma
	// 1 -> subtrai
	// 2 -> copia do registrador para RAM
	// 3 -> copia da RAM para o registrador
	// 4 -> salva conteudo externo no registrador
	// 5 -> obtem conteudo externo do registrador

    criarRAM_vazia(2);
    
    Instrucao trecho1[3] = {
        {4, 1, multiplicando, -1},
        {2, 1, 1, -1},
        {-1, -1, -1, -1}
    };

    setPrograma(cpu, trecho1);
    iniciarCPU(cpu);

    for(int i = 0; i < multiplicador; i++){
        Instrucao trecho2[2];

        Instrucao inst3 = {0, 0, 1, 0};
        trecho2[0] = inst3;

        Instrucao inst4 = {-1, -1, -1, -1};
        trecho2[1] = inst4;

        setPrograma(cpu, trecho2);
        iniciarCPU(cpu);
    }

    Instrucao trecho3[3] = {
    {3, 1, 0, -1},
    {5, 1, -1, -1},
    {-1, -1, -1, -1} 
    };

    setPrograma(cpu, trecho3);
    iniciarCPU(cpu);

    printf("Resultado: %d\n", trecho3[1].add2);
}


void programaAleatorio(CPU *cpu, int qdeinstrucoes){
	Instrucao *umPrograma = malloc(sizeof(Instrucao) * qdeinstrucoes);
	srand(time(NULL));
	int tamanhoRAM = 1000;
	criarRAM_aleatoria(tamanhoRAM);
	
	for(int i = 0; i < qdeinstrucoes-1; i++){
		Instrucao inst;
		inst.opcode = rand() % 2;
		inst.add1 = rand() % tamanhoRAM;
		inst.add2 = rand() % tamanhoRAM;
		inst.add3 = rand() % tamanhoRAM;
		umPrograma[i] = inst;
	}

	Instrucao ultima;
	ultima.opcode = -1;
	umPrograma[qdeinstrucoes-1] = ultima;

	setPrograma(cpu, umPrograma);
	iniciarCPU(cpu);

}

void programaDiv(CPU *cpu, int dividendo, int divisor){
    criarRAM_vazia(4);
    
    Instrucao trecho1[5] = {
        {4, 1, dividendo, -1},  
        {2, 1, 0, -1},
        {4, 2, divisor, -1},
        {2, 2, 1, -1},
        {-1, -1, -1, -1}        
    };
    setPrograma(cpu, trecho1);
    iniciarCPU(cpu);

    Instrucao trecho2[3] = {
        {4, 1, 1, -1},
        {2, 1, 2, -1},
        {-1, -1, -1, -1}
    };
    setPrograma(cpu, trecho2);
    iniciarCPU(cpu);

    while (dividendo > divisor) {
        
        Instrucao trecho3[5] = {
            {1, 0, 1, 0},
            {0, 2, 3, 3},
            {3, 1, 0, -1},
            {5, 1, -1, -1},
            {-1, -1, -1, -1}
        };
        setPrograma(cpu, trecho3);
        iniciarCPU(cpu);

        dividendo = trecho3[3].add2;
    }

    Instrucao trecho4[3] = {
        {3, 1, 3, -1},
        {3, 1, -1, -1},
        {-1, -1, -1, -1}
    };
    setPrograma(cpu, trecho4);
    iniciarCPU(cpu);

    printf("O resultado da divisão é: %.3d", trecho4[1].add2);
}

//programaFibonacci
void programaFibonacci(CPU *cpu, int n){

    criarRAM_vazia(3);

    Instrucao trecho1[5] = {
        {4, 1, 0, -1},
        {2, 1, 0, -1},
        {4, 2, 1, -1},
        {2, 2, 1, -1},
        {-1, -1, -1, -1}
    };
    cpu->programa = trecho1;
    setPrograma(cpu, trecho1);
    iniciarCPU(cpu);

    for (int i = 2; i < n; i++){
        Instrucao trecho2[6] = {
            {0, 0, 1, 2},
            {3, 1, 1, -1},
            {3, 2, 2, -1},
            {2, 1, 0, -1},
            {2, 2, 1, -1},
            {-1, -1, -1, -1}
        };
        setPrograma(cpu, trecho2);
    }
    
    Instrucao trecho3[3] = {
        {3, 1, 1, -1},
        {5, 1, -1, -1},
        {-1, -1, -1, -1}
    };    
    
    setPrograma(cpu, trecho3);
}


void programaSomaMatriz(CPU *cpu, int cardinalidade){
	int matriz1[cardinalidade][cardinalidade];
	int matriz2[cardinalidade][cardinalidade];
	srand(time(NULL));
	
	for(int i = 0; i < cardinalidade; i++){
		for(int j = 0; j < cardinalidade; i++){
			matriz1[i][j] = rand() % 100;
			matriz2[i][j] = rand() % 100;
		}
	}

	criarRAM_vazia(27);
	int endRam = 0;
	for(int i = 0; i < cardinalidade; i++){
		for(int j = 0; j < cardinalidade; i++){
			Instrucao trecho1[3] = {
				{4, 1, matriz1[i][j], -1},
				{2, 1, endRam, -1},
				{-1, -1, -1, -1}
			};

			setPrograma(cpu, trecho1);
			iniciarCPU(cpu);

			endRam++;
		}
	}

	for(int i = 0; i < cardinalidade; i++){
		for(int j = 0; j < cardinalidade; i++){
			Instrucao trecho2[3] = {
				{4, 1, matriz2[i][j], -1},
				{2, 1, endRam, -1},
				{-1, -1, -1, -1}
			};

			setPrograma(cpu, trecho2);
			iniciarCPU(cpu);

			endRam++;
		}
	}

	endRam = 0;
	int delta = 9;
	for(int i = 0; i < cardinalidade; i++){
		for(int i = 0; i < cardinalidade; i++){
			Instrucao trecho3[2] = {
				{0, endRam, endRam+delta, endRam+(2*delta)},
				{-1, -1, -1, -1}
			};

			setPrograma(cpu, trecho3);
			iniciarCPU(cpu);

			endRam++;
		}
	}
}

//programaBhaskara

int main(){

	printf("Iniciando programa...\n");

	CPU cpu = {0};
	programaAleatorio(&cpu, 10);

	printf("Terminando programa...\n");
	return 0;
}
