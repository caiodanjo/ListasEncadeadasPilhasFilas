#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char dados[MAX];
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

void push(Pilha* p, char c) {
    if (!esta_cheia(p)) {
        p->dados[++p->topo] = c;
    }
}

char pop(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[p->topo--];
    }
    return '\0';
}

void inverter_string(char* str) {
    Pilha pilha;
    inicializar(&pilha);

    int i;
    int n = strlen(str);

    for (i = 0; i < n; i++) {
        push(&pilha, str[i]);
    }

    for (i = 0; i < n; i++) {
        str[i] = pop(&pilha);
    }
}

int main() {
    char str[] = "hello";
    
    printf("Original: %s\n", str);
    inverter_string(str);
    printf("Invertida: %s\n", str);

    return 0;
}
