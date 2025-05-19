#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* proximo;
} No;

void inserir_inicio(No** cabeca, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = *cabeca;
    *cabeca = novo;
}

void rotacionar_lista(No** cabeca, int k) {
    if (*cabeca == NULL || k == 0) return;

    No* atual = *cabeca;
    int tamanho = 1;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
        tamanho++;
    }

    atual->proximo = *cabeca;

    k = k % tamanho;
    int passos_para_novo_final = tamanho - k;

    No* novo_final = *cabeca;
    for (int i = 1; i < passos_para_novo_final; i++) {
        novo_final = novo_final->proximo;
    }

    *cabeca = novo_final->proximo;

    novo_final->proximo = NULL;
}


void imprimir_lista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d → ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_inicio(&lista, 5);
    inserir_inicio(&lista, 4);
    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 1);

    printf("Lista original:\n");
    imprimir_lista(lista);

    rotacionar_lista(&lista, 2);

    printf("Lista após rotacionar 2 posições:\n");
    imprimir_lista(lista);

    return 0;
}
