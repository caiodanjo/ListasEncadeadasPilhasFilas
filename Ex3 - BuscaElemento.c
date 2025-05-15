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

int buscar_elemento(No* cabeca, int valor) {
    No* atual = cabeca;
    while (atual != NULL) {
        if (atual->dado == valor) {
            return 1;
        }
        atual = atual->proximo;
    }
    return 0;
}

int main() {
    No* lista = NULL;

    inserir_inicio(&lista, 10);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 20);

    imprimir_lista(lista);

    int valor;
    printf("Digite um número para buscar na lista: ");
    scanf("%d", &valor);

    if (buscar_elemento(lista, valor)) {
        printf("Valor %d encontrado na lista.\n", valor);
    } else {
        printf("Valor %d não encontrado na lista.\n", valor);
    }

    return 0;
}
