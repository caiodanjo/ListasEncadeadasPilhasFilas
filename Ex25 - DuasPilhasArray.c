#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo1;
    int topo2;
} DuasPilhas;

void inicializar(DuasPilhas* p) {
    p->topo1 = -1;
    p->topo2 = MAX;
}

void push1(DuasPilhas* p, int valor) {
    if (p->topo1 + 1 == p->topo2) {
        printf("Overflow na Pilha 1\n");
        return;
    }
    p->dados[++(p->topo1)] = valor;
}

void push2(DuasPilhas* p, int valor) {
    if (p->topo1 + 1 == p->topo2) {
        printf("Overflow na Pilha 2\n");
        return;
    }
    p->dados[--(p->topo2)] = valor;
}

int pop1(DuasPilhas* p) {
    if (p->topo1 == -1) {
        printf("Underflow na Pilha 1\n");
        return INT_MIN;
    }
    return p->dados[(p->topo1)--];
}

int pop2(DuasPilhas* p) {
    if (p->topo2 == MAX) {
        printf("Underflow na Pilha 2\n");
        return INT_MIN;
    }
    return p->dados[(p->topo2)++];
}

int topo1(DuasPilhas* p) {
    if (p->topo1 == -1) return INT_MIN;
    return p->dados[p->topo1];
}

int topo2(DuasPilhas* p) {
    if (p->topo2 == MAX) return INT_MIN;
    return p->dados[p->topo2];
}

void imprimir_pilha1(DuasPilhas* p) {
    printf("Pilha 1: ");
    for (int i = 0; i <= p->topo1; i++)
        printf("%d ", p->dados[i]);
    printf("\n");
}

void imprimir_pilha2(DuasPilhas* p) {
    printf("Pilha 2: ");
    for (int i = MAX - 1; i >= p->topo2; i--)
        printf("%d ", p->dados[i]);
    printf("\n");
}

int main() {
    DuasPilhas pilhas;
    inicializar(&pilhas);

    push1(&pilhas, 10);
    push1(&pilhas, 20);
    push1(&pilhas, 30);
    imprimir_pilha1(&pilhas);

    push2(&pilhas, 100);
    push2(&pilhas, 200);
    push2(&pilhas, 300);
    imprimir_pilha2(&pilhas);

    printf("Pop Pilha 1: %d\n", pop1(&pilhas));
    printf("Pop Pilha 2: %d\n", pop2(&pilhas));
    imprimir_pilha1(&pilhas);
    imprimir_pilha2(&pilhas);

    return 0;
}
