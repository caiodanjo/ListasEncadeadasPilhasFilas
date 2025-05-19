#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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

void push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Stack overflow!\n");
        exit(1);
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha* p) {
    if (esta_vazia(p)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return p->dados[(p->topo)--];
}

int topo(Pilha* p) {
    if (esta_vazia(p)) return INT_MIN;
    return p->dados[p->topo];
}

typedef struct {
    Pilha entrada;
    Pilha saida;
} Fila;

void inicializar_fila(Fila* f) {
    inicializar(&f->entrada);
    inicializar(&f->saida);
}

void enqueue(Fila* f, int valor) {
    push(&f->entrada, valor);
}

int dequeue(Fila* f) {
    if (esta_vazia(&f->saida)) {
        while (!esta_vazia(&f->entrada)) {
            int temp = pop(&f->entrada);
            push(&f->saida, temp);
        }
    }
    if (esta_vazia(&f->saida)) {
        printf("Fila vazia!\n");
        exit(1);
    }
    return pop(&f->saida);
}

int frente(Fila* f) {
    if (esta_vazia(&f->saida)) {
        while (!esta_vazia(&f->entrada)) {
            push(&f->saida, pop(&f->entrada));
        }
    }
    return topo(&f->saida);
}

int main() {
    Fila f;
    inicializar_fila(&f);

    enqueue(&f, 10);
    enqueue(&f, 20);
    enqueue(&f, 30);

    printf("Dequeued: %d\n", dequeue(&f));
    printf("Frente: %d\n", frente(&f));

    enqueue(&f, 40);
    printf("Dequeued: %d\n", dequeue(&f));
    printf("Dequeued: %d\n", dequeue(&f));
    printf("Dequeued: %d\n", dequeue(&f));

    return 0;
}
