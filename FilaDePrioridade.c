#include <stdio.h>
#include <stdlib.h>

#define MAX_TAM 100 


typedef struct {
    int armazena[MAX_TAM]; 
    int size; 
} FilaDePrioridade;

void pqIniciar(FilaDePrioridade *pq) {
    pq->size = 0;
}


void pqInserir(FilaDePrioridade *pq, int valor) {
    if (pq->size == MAX_TAM) {
        printf("Erro: fila de prioridade cheia\n");
        exit(1);
    }

    int i = pq->size - 1; 

   
    while (i >= 0 && valor < pq->armazena[i]) {
        pq->armazena[i + 1] = pq->armazena[i];
        i--;
    }

    
    pq->armazena[i + 1] = valor;
    pq->size++;
}


int pqdeletar(FilaDePrioridade *pq) {
    if (pq->size == 0) {
        printf("Erro: fila de prioridade vazia\n");
        exit(1);
    }

    int min = pq->armazena[0]; 
    pq->size--;

    
    for (int i = 0; i < pq->size; i++) {
        pq->armazena[i] = pq->armazena[i + 1];
    }

    return min;
}


int pqEmpty(FilaDePrioridade *pq) {
    return (pq->size == 0);
}

int main() {
    int input[] = {20, 13, 4, 2, 18, 40, 2, 19, 1};
    int size = sizeof(input) / sizeof(int);

    
    FilaDePrioridade pq;
    pqIniciar(&pq);

   
    for (int i = 0; i < size; i++) {
        pqInserir(&pq, input[i]);
    }

    
    while (!pqEmpty(&pq)) {
        printf("%d ", pqdeletar(&pq));
    }

    return 0;
}


