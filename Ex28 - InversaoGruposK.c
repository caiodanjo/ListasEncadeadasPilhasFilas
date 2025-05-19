#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

No* novo_no(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

No* inverter_grupos(No* cabeca, int K) {
    No* atual = cabeca;
    No* anterior = NULL;
    No* proximo = NULL;
    int count = 0;

    No* temp = cabeca;
    for (int i = 0; i < K; i++) {
        if (!temp) return cabeca;
        temp = temp->prox;
    }

    while (atual != NULL && count < K) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
        count++;
    }

    if (proximo != NULL)
        cabeca->prox = inverter_grupos(proximo, K);

    return anterior;
}

void imprimir_lista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->valor);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

void liberar_lista(No* cabeca) {
    while (cabeca != NULL) {
        No* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}

int main() {
    No* lista = novo_no(1);
    lista->prox = novo_no(2);
    lista->prox->prox = novo_no(3);
    lista->prox->prox->prox = novo_no(4);
    lista->prox->prox->prox->prox = novo_no(5);

    int K = 2;

    printf("Original: ");
    imprimir_lista(lista);

    lista = inverter_grupos(lista, K);

    printf("Invertida por grupos de %d: ", K);
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}
