#include <stdio.h>
#include <stdlib.h>

typedef struct NoPilha {
    int dado;
    struct NoPilha* proximo;
} NoPilha;

int esta_vazia(NoPilha* topo) {
    return topo == NULL;
}

void push(NoPilha** topo, int valor) {
    NoPilha* novo = (NoPilha*)malloc(sizeof(NoPilha));
    if (novo == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    novo->dado = valor;
    novo->proximo = *topo;
    *topo = novo;
}

int pop(NoPilha** topo) {
    if (esta_vazia(*topo)) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }
    NoPilha* temp = *topo;
    int valor = temp->dado;
    *topo = temp->proximo;
    free(temp);
    return valor;
}

int topo(NoPilha* topo) {
    if (esta_vazia(topo)) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }
    return topo->dado;
}

int main() {
    NoPilha* pilha = NULL;

    push(&pilha, 5);
    push(&pilha, 10);
    push(&pilha, 15);

    printf("Topo: %d\n", topo(pilha));

    while (!esta_vazia(pilha)) {
        printf("Pop: %d\n", pop(&pilha));
    }

    return 0;
}
