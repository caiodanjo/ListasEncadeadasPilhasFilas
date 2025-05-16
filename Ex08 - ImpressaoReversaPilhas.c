#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int dado;
    struct No* proximo;
} No;

typedef struct Pilha {
    int dado;
    struct Pilha* proximo;
} Pilha;

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

void push(Pilha** topo, int valor) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if (novo == NULL) {
        printf("Erro ao alocar memória para a pilha.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->proximo = *topo;
    *topo = novo;
}

int pop(Pilha** topo) {
    if (*topo == NULL) {
        printf("Pilha vazia.\n");
        exit(1);
    }
    Pilha* temp = *topo;
    int valor = temp->dado;
    *topo = temp->proximo;
    free(temp);
    return valor;
}

int pilha_vazia(Pilha* topo) {
    return topo == NULL;
}

void imprimir_lista_reversa(No* cabeca) {
    Pilha* pilha = NULL;
    No* atual = cabeca;

    while (atual != NULL) {
        push(&pilha, atual->dado);
        atual = atual->proximo;
    }

    printf("\nLista em ordem reversa:\n");
    while (!pilha_vazia(pilha)) {
        printf("%d -> ", pop(&pilha));
    }
    printf("NULL\n");
}

int main() {
    No* lista = NULL;

    inserir_inicio(&lista, 10);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 20);

    printf("Lista original:\n");
    imprimir_lista(lista);

    imprimir_lista_reversa(lista);

    return 0;
}
