#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct{
    int add1;
    int add2;
    int add3;
    int opcode;
} Instrucao;

typedef struct{
    int registgrador1;
    int registrador2;
    int pc
    Instrucao *programa;
} CPU;
