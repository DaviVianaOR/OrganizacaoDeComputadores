#ifndef Programas25_H
#define Programas25_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RAM25.h"
#include "CPU25.h"

void programaMult(CPU *cpu, int multiplicando, int multiplicador);
void programaAleatorio(CPU *cpu, int qdeinstrucoes);
void programaDiv(CPU *cpu, int dividendo, int divisor);
void programaFibonacci(CPU *cpu, int n);
void programaSomaMatriz(CPU *cpu, int cardinalidade);
int main();


#endif