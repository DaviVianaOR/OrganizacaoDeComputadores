#ifndef CPU25_H
#define CPU25_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RAM25.h"

typedef struct {
    int opcode;
    int add1;
    int add2;
    int add3;
} Instrucao;

typedef struct {
    int registrador1;
    int registrador2;
    int pc;
    Instrucao *programa;
} CPU;

Instrucao* setPrograma(CPU *cpu, Instrucao *programaAux);
void iniciarCPU(CPU *cpu);

#endif