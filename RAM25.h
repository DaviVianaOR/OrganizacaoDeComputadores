#ifndef RAM25_H
#define RAM25_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *alocaRAM(int tamanho);
void criarRAM_vazia(int tamanho);
void criarRAM_aleatoria(int tamanho);
void liberaRAM();
void setDado(int endereco, int conteudo);
int getDado(int endereco);
void imprimir(int tamanho);
int main();


#endif