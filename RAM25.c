#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RAM25.h"

int *memoria;

int *alocaRAM(int tamanho){
    memoria = (int *)malloc(tamanho * sizeof(int));
    
    if(memoria == NULL){
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    return memoria;
}

void liberaRAM(){
    free(memoria);
    memoria = NULL;
}

void criarRAM_vazia(int tamanho){
    for(int i = 0; i < tamanho; i++){
        memoria[i] = 0;
    }
}

void criarRAM_aleatoria(int tamanho){
    srand(time(NULL));

    for(int i = 0; i < tamanho; i++){
        memoria[i] = rand() % 1000;
    }
}

void setDado(int endereco, int conteudo){
    memoria[endereco] = conteudo;
}

int getDado(int endereco){
    return memoria[endereco];
}

void imprimir(int tamanho){
    printf("Conteudo da RAM:\n");
    for(int i = 0; i < tamanho; i++){
        printf("%d, ", memoria[i]);
    }
}


int main(){
    int tamanho = 100;
    
    alocaRAM(tamanho);
    criarRAM_aleatoria(tamanho);
    imprimir(tamanho);
    liberaRAM();

    return 0;
}
