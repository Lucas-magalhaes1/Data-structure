#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CARROS 4
#define MAX_PLACA 7

struct Carro {
    char placa[MAX_PLACA];
    int movimentos;
};

struct Fila {
    struct Carro carros[MAX_CARROS];
    int inicio;
    int fim;
    int tamanho;
};

void inicializarFila(struct Fila *fila) {
    fila->inicio = 0;
    fila->fim = -1;
    fila->tamanho = 0;
}

int estaCheia(struct Fila *fila) {
    return fila->tamanho == MAX_CARROS;
}

int estaVazia(struct Fila *fila) {
    return fila->tamanho == 0;
}

void adicionarCarro(struct Fila *fila, char *placa) {
    if (estaCheia(fila)) {
        printf("Não há vagas disponíveis para o carro de placa, entrou na fila de espera %s\n", placa);
        return;
    }

    struct Carro novoCarro;
    strcpy(novoCarro.placa, placa);
    novoCarro.movimentos = 0;

    fila->fim = (fila->fim + 1) % MAX_CARROS;
    fila->carros[fila->fim] = novoCarro;
    fila->tamanho++;

    printf("O carro de placa %s entrou no estacionamento\n", placa);
}

void removerCarro(struct Fila *fila, char *placa) {
    if (estaVazia(fila)) {
        printf("Não há carros para remover\n");
        return;
    }

    int posicao = -1;
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + i) % MAX_CARROS;
        if (strcmp(fila->carros[index].placa, placa) == 0) {
            posicao = index;
            break;
        }
    }

    if (posicao == -1) {
        printf("O carro de placa %s não está no estacionamento\n", placa);
        return;
    }

    struct Carro carroRemovido = fila->carros[posicao];
    printf("O carro de placa %s saiu do estacionamento\n", placa);

    if (posicao == fila->inicio) {
        fila->inicio = (fila->inicio + 1) % MAX_CARROS;
    } else {
        for (int i = posicao; i < fila->tamanho - 1; i++) {
            fila->carros[i] = fila->carros[i + 1];
            fila->carros[i].movimentos++;
        }
    }

    fila->tamanho--;

    if (!estaVazia(fila)) {
        struct Carro ultimoCarro = fila->carros[(fila->inicio + fila->tamanho - 1) % MAX_CARROS];
        printf("O carro de placa %s entrou no estacionamento\n", ultimoCarro.placa);
    }
}

void imprimirFila(struct Fila *fila) {
    if (estaVazia(fila)) {
        printf("Não há carros no estacionamento\n");
        return;
    }

    printf("Carros no estacionamento:\n");
    for (int i = 0; i < fila->tamanho; i++) {
        int index = (fila->inicio + i) % MAX_CARROS;
        printf ("Placa: %s | Movimentos: %d\n", fila->carros[index].placa, fila->carros[index].movimentos);
}

}

int main() {
struct Fila fila;
inicializarFila(&fila);
int opcao = 0;
while (opcao != 4) {
    printf("\nEscolha uma opção:\n");
    printf("1. Adicionar carro\n");
    printf("2. Remover carro\n");
    printf("3. Imprimir carros no estacionamento\n");
    printf("4. Sair\n");

    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            printf("Digite a placa do carro (formato: ABC1234): ");
            char placa[MAX_PLACA];
            scanf("%s", placa);
            adicionarCarro(&fila, placa);
            break;
        case 2:
            printf("Digite a placa do carro a ser removido (formato: ABC1234): ");
            char placaRemover[MAX_PLACA];
            scanf("%s", placaRemover);
            removerCarro(&fila, placaRemover);
            break;
        case 3:
            imprimirFila(&fila);
            break;
        case 4:
            printf("Encerrando o programa\n");
            break;
        default:
            printf("Opção inválida\n");
            break;
    }
}

return 0;

}






