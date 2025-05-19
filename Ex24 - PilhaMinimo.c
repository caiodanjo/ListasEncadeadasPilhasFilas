#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

typedef struct {
    Pilha principal;
    Pilha minimos;
} PilhaComMinimo;

void inicializar(Pilha* p) {
    p->topo = -1;
}

int vazia(Pilha* p) {
    return p->topo == -1;
}

int cheia(Pilha* p) {
    return p->topo == MAX - 1;
}

void empilhar(Pilha* p, int valor) {
    if (cheia(p)) return;
    p->dados[++(p->topo)] = valor;
}

int desempilhar(Pilha* p) {
    if (vazia(p)) return INT_MIN;
    return p->dados[(p->topo)--];
}

int topo(Pilha* p) {
    if (vazia(p)) return INT_MIN;
    return p->dados[p->topo];
}

void inicializar_pilha(PilhaComMinimo* p) {
    inicializar(&p->principal);
    inicializar(&p->minimos);
}

void push(PilhaComMinimo* p, int valor) {
    empilhar(&p->principal, valor);
    if (vazia(&p->minimos) || valor <= topo(&p->minimos)) {
        empilhar(&p->minimos, valor);
    }
}

void pop(PilhaComMinimo* p) {
    if (vazia(&p->principal)) return;
    int removido = desempilhar(&p->principal);
    if (removido == topo(&p->minimos)) {
        desempilhar(&p->minimos);
    }
}

int top(PilhaComMinimo* p) {
    return topo(&p->principal);
}

int obter_minimo(PilhaComMinimo* p) {
    return topo(&p->minimos);
}

int main() {
    PilhaComMinimo pilha;
    inicializar_pilha(&pilha);

    push(&pilha, 3);
    push(&pilha, 5);
    printf("Min: %d\n", obter_minimo(&pilha)); // 3

    push(&pilha, 2);
    push(&pilha, 1);
    printf("Min: %d\n", obter_minimo(&pilha)); // 1

    pop(&pilha);
    printf("Min: %d\n", obter_minimo(&pilha)); // 2

    pop(&pilha);
    printf("Topo: %d\n", top(&pilha));          // 5
    printf("Min: %d\n", obter_minimo(&pilha)); // 3

    return 0;
}
