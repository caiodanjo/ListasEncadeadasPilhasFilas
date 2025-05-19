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

void remover_todas_ocorrencias(No** cabeca, int valor) {
    No* atual = *cabeca;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            No* temp = atual;
            if (anterior == NULL) {
                *cabeca = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            atual = atual->proximo;
            free(temp);
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

void imprimir_lista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d -> ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 1);
    inserir_inicio(&lista, 2);
    inserir_inicio(&lista, 3);
    inserir_inicio(&lista, 4);
    inserir_inicio(&lista, 3);

    printf("Lista original:\n");
    imprimir_lista(lista);

    remover_todas_ocorrencias(&lista, 3);

    printf("Lista após remover todas as ocorrências de 3:\n");
    imprimir_lista(lista);

    return 0;
}
