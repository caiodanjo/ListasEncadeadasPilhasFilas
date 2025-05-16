#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

int esta_cheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void push(Pilha* p, int valor) {
    if (!esta_cheia(p)) {
        p->dados[++p->topo] = valor;
    }
}

int pop(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[p->topo--];
    }
    return -1;
}

int topo(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[p->topo];
    }
    return -1;
}

void imprimir_pilha(Pilha* p) {
    printf("Pilha (topo -> base): ");
    for (int i = p->topo; i >= 0; i--) {
        printf("%d ", p->dados[i]);
    }
    printf("\n");
}

void ordenar_pilha(Pilha* original) {
    Pilha auxiliar;
    inicializar(&auxiliar);

    while (!esta_vazia(original)) {
        int temp = pop(original);

        while (!esta_vazia(&auxiliar) && topo(&auxiliar) > temp) {
            push(original, pop(&auxiliar));
        }

        push(&auxiliar, temp);
    }

    while (!esta_vazia(&auxiliar)) {
        push(original, pop(&auxiliar));
    }
}

int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 4);
    push(&p, 1);
    push(&p, 3);
    push(&p, 2);

    printf("Antes da ordenação:\n");
    imprimir_pilha(&p);

    ordenar_pilha(&p);

    printf("Após a ordenação:\n");
    imprimir_pilha(&p);

    return 0;
}
