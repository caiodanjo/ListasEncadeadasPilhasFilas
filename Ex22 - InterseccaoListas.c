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

int comprimento_lista(No* cabeca) {
    int comprimento = 0;
    while (cabeca != NULL) {
        comprimento++;
        cabeca = cabeca->proximo;
    }
    return comprimento;
}

No* encontrar_intersecao(No* lista1, No* lista2) {
    int len1 = comprimento_lista(lista1);
    int len2 = comprimento_lista(lista2);

    while (len1 > len2) {
        lista1 = lista1->proximo;
        len1--;
    }
    while (len2 > len1) {
        lista2 = lista2->proximo;
        len2--;
    }

    while (lista1 != NULL && lista2 != NULL) {
        if (lista1 == lista2) {
            return lista1;
        }
        lista1 = lista1->proximo;
        lista2 = lista2->proximo;
    }

    return NULL;
}


void imprimir_lista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d -> ", cabeca->valor);
        cabeca = cabeca->proximo;
    }
    printf("NULL\n");
}

int main() {
    No* comum = (No*)malloc(sizeof(No));
    comum->valor = 30;
    comum->proximo = (No*)malloc(sizeof(No));
    comum->proximo->valor = 40;
    comum->proximo->proximo = NULL;

    No* lista1 = (No*)malloc(sizeof(No));
    lista1->valor = 10;
    lista1->proximo = (No*)malloc(sizeof(No));
    lista1->proximo->valor = 20;
    lista1->proximo->proximo = comum;

    No* lista2 = (No*)malloc(sizeof(No));
    lista2->valor = 15;
    lista2->proximo = comum;

    No* intersecao = encontrar_intersecao(lista1, lista2);

    if (intersecao) {
        printf("Interseção encontrada no nó com valor: %d\n", intersecao->valor);
    } else {
        printf("Nenhuma interseção encontrada.\n");
    }

    return 0;
}
