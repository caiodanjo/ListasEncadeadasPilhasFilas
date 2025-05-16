#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

void inicializar(Fila* f) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = 0;
}

int esta_vazia(Fila* f) {
    return f->tamanho == 0;
}

int esta_cheia(Fila* f) {
    return f->tamanho == MAX;
}

void enfileirar(Fila* f, int valor) {
    if (esta_cheia(f)) {
        printf("Fila cheia!\n");
        return;
    }
    f->dados[f->fim] = valor;
    f->fim = (f->fim + 1) % MAX;
    f->tamanho++;
}

int desenfileirar(Fila* f) {
    if (esta_vazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    int valor = f->dados[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return valor;
}

int frente(Fila* f) {
    if (esta_vazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }
    return f->dados[f->inicio];
}

void exibir_fila(Fila* f) {
    if (esta_vazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    printf("Fila: ");
    int i = f->inicio;
    for (int count = 0; count < f->tamanho; count++) {
        printf("%d ", f->dados[i]);
        i = (i + 1) % MAX;
    }
    printf("\n");
}
int main() {
    Fila f;
    inicializar(&f);

    enfileirar(&f, 10);
    enfileirar(&f, 20);
    enfileirar(&f, 30);

    printf("Frente: %d\n", frente(&f));
    exibir_fila(&f);

    printf("Removido: %d\n", desenfileirar(&f));
    printf("Frente: %d\n", frente(&f));
    exibir_fila(&f);

    return 0;
}
