#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "RAM25.h"

int tamanho = 1000;

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


/*int main(){
    int tamanho = 100;
    
    alocaRAM(tamanho);              // aloca espaço na RAM 
    criarRAM_aleatoria(tamanho);    // preenche RAM com numeros aleatorios
    setDado(0, 42);                 // armazena '42' no endereço 0
    int valor = getDado(0);         // le o valor do endereço 0 acima (retorna 42)
    imprimir(tamanho);              // mostra todo conteudo da RAM
    liberaRAM();                    // libera a memória


    return 0;
}*/
