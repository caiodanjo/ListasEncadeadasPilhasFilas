#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_MAX 100

typedef struct {
    int dados[TAMANHO_MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int esta_vazia(Pilha* p) {
    return p->topo == -1;
}

int esta_cheia(Pilha* p) {
    return p->topo == TAMANHO_MAX - 1;
}

void push(Pilha* p, int valor) {
    if (esta_cheia(p)) {
        printf("Erro: pilha cheia.\n");
        return;
    }
    p->topo++;
    p->dados[p->topo] = valor;
}

int pop(Pilha* p) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }
    int valor = p->dados[p->topo];
    p->topo--;
    return valor;
}

int topo(Pilha* p) {
    if (esta_vazia(p)) {
        printf("Erro: pilha vazia.\n");
        exit(1);
    }
    return p->dados[p->topo];
}

int main() {
    Pilha p;
    inicializar(&p);

    push(&p, 10);
    push(&p, 20);
    push(&p, 30);

    printf("Topo da pilha: %d\n", topo(&p));

    while (!esta_vazia(&p)) {
        printf("Pop: %d\n", pop(&p));
    }

    return 0;
}
