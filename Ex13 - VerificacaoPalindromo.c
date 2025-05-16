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

int palindromo(const char* str) {
    Pilha pilha;
    inicializar(&pilha);

    int n = strlen(str);

    for (int i = 0; i < n; i++) {
        push(&pilha, str[i]);
    }

    for (int i = 0; i < n; i++) {
        if (str[i] != pop(&pilha)) {
            return 0;
        }
    }

    return 1;
}

int main() {
    const char* palavra1 = "radar";
    const char* palavra2 = "codigo";

    if (palindromo(palavra1)) {
        printf("\"%s\" é um palíndromo.\n", palavra1);
    } else {
        printf("\"%s\" não é um palíndromo.\n", palavra1);
    }
    
    if (palindromo(palavra2)) {
        printf("\"%s\" é um palíndromo.\n", palavra2);
    } else {
        printf("\"%s\" não é um palíndromo.\n", palavra2);
    }

    return 0;
}
