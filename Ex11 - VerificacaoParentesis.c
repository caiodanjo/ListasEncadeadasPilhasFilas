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

char topo(Pilha* p) {
    if (!esta_vazia(p)) {
        return p->dados[p->topo];
    }
    return '\0';
}

int corresponde(char abre, char fecha) {
    return (abre == '(' && fecha == ')') ||
           (abre == '[' && fecha == ']') ||
           (abre == '{' && fecha == '}');
}

int verificar_balanceamento(const char* expressao) {
    Pilha pilha;
    inicializar(&pilha);

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (c == '(' || c == '[' || c == '{') {
            push(&pilha, c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (esta_vazia(&pilha)) return 0;
            char topo_pilha = pop(&pilha);
            if (!corresponde(topo_pilha, c)) return 0;
        }
    }

    return esta_vazia(&pilha);
}

int main() {
    const char* teste1 = "({[]})";
    const char* teste2 = "({[})";
    
    printf("Teste 1: %s => %s\n", teste1, verificar_balanceamento(teste1) ? "válida" : "inválida");
    printf("Teste 2: %s => %s\n", teste2, verificar_balanceamento(teste2) ? "válida" : "inválida");

    return 0;
}
