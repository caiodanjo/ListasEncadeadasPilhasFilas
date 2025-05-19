#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* prox;
} No;

// Função auxiliar para reverter a lista
No* reverter_lista(No* cabeca) {
    No* anterior = NULL;
    No* atual = cabeca;
    No* proximo = NULL;

    while (atual != NULL) {
        proximo = atual->prox;
        atual->prox = anterior;
        anterior = atual;
        atual = proximo;
    }
    return anterior;
}

// Função para verificar se a lista é palíndromo
int eh_palindromo(No* cabeca) {
    if (cabeca == NULL || cabeca->prox == NULL) return 1;

    // Passo 1: Encontrar o meio
    No *lento = cabeca, *rapido = cabeca;
    while (rapido->prox != NULL && rapido->prox->prox != NULL) {
        lento = lento->prox;
        rapido = rapido->prox->prox;
    }

    // Passo 2: Reverter segunda metade
    No* segunda_metade = reverter_lista(lento->prox);

    // Passo 3: Comparar
    No* p1 = cabeca;
    No* p2 = segunda_metade;
    int eh_palin = 1;
    while (p2 != NULL) {
        if (p1->valor != p2->valor) {
            eh_palin = 0;
            break;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }

    // Passo 4: Restaurar a lista original
    lento->prox = reverter_lista(segunda_metade);

    return eh_palin;
}

// Funções auxiliares
No* novo_no(int valor) {
    No* no = (No*)malloc(sizeof(No));
    no->valor = valor;
    no->prox = NULL;
    return no;
}

void imprimir_lista(No* cabeca) {
    while (cabeca != NULL) {
        printf("%d ", cabeca->valor);
        cabeca = cabeca->prox;
    }
    printf("\n");
}

void liberar_lista(No* cabeca) {
    while (cabeca) {
        No* temp = cabeca;
        cabeca = cabeca->prox;
        free(temp);
    }
}

int main() {
    No* lista = novo_no(1);
    lista->prox = novo_no(2);
    lista->prox->prox = novo_no(3);
    lista->prox->prox->prox = novo_no(2);
    lista->prox->prox->prox->prox = novo_no(1);

    printf("Lista: ");
    imprimir_lista(lista);

    if (eh_palindromo(lista))
        printf("É palíndromo.\n");
    else
        printf("Não é palíndromo.\n");

    printf("Após verificação (lista restaurada): ");
    imprimir_lista(lista);

    liberar_lista(lista);
    return 0;
}
