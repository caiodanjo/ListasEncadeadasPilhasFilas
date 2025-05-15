#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

No* criar_no(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->proximo = NULL;
    return novo;
}

void inserir_inicio(No** cabeca, int valor) {
    No* novo = criar_no(valor);
    novo->proximo = *cabeca;
    *cabeca = novo;
}

void inserir_fim(No** cabeca, int valor) {
    No* novo = criar_no(valor);

    if (*cabeca == NULL) {
        *cabeca = novo;
        return;
    }

    No* atual = *cabeca;
    while (atual->proximo != NULL) {
        atual = atual->proximo;
    }

    atual->proximo = novo;
}

void imprimir_lista(No* cabeca) {
    No* atual = cabeca;
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}

void inverter_lista(No** cabeca) {
    No* anterior = NULL;
    No* atual = *cabeca;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->proximo;
        atual->proximo = anterior;
        anterior = atual;
        atual = proximo;
    }

    *cabeca = anterior;
}

int main() {
    int valor;
    No* lista = NULL;

    inserir_inicio(&lista, 10);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 20);

    printf("Lista antes de inverter:\n");
    imprimir_lista(lista);

    inverter_lista(&lista);

    printf("\nLista após a inversão:\n");
    imprimir_lista(lista);


    return 0;
}
