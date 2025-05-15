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

void inserir_posicao(No** cabeca, int valor, int posicao) {
    if (posicao <= 0 || *cabeca == NULL) {
        inserir_inicio(cabeca, valor);
        return;
    }

    No* atual = *cabeca;
    int indice = 0;

    while (atual->proximo != NULL && indice < posicao - 1) {
        atual = atual->proximo;
        indice++;
    }

    No* novo = criar_no(valor);
    novo->proximo = atual->proximo;
    atual->proximo = novo;
}

int main() {
    No* lista = NULL;

    inserir_inicio(&lista, 10);
    inserir_fim(&lista, 5);
    inserir_fim(&lista, 20);

    printf("Lista original:\n");
    imprimir_lista(lista);

    int valor, posicao;
    printf("Digite um valor para ser inserido: ");
    scanf("%d", &valor);
    printf("Digite uma posição para inserir: ");
    scanf("%d", &posicao);

    inserir_posicao(&lista, valor, posicao);

    printf("\nLista após inserção:\n");
    imprimir_lista(lista);

    return 0;
}
