#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

void inicializar(Pilha* p) {
    p->topo = -1;
}

void push(Pilha* p, int valor) {
    if (p->topo == MAX - 1) {
        printf("Pilha cheia!\n");
        exit(1);
    }
    p->dados[++(p->topo)] = valor;
}

int pop(Pilha* p) {
    if (p->topo == -1) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->dados[(p->topo)--];
}

int eh_operador(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int avaliar_posfixa(const char* expressao) {
    Pilha p;
    inicializar(&p);

    char token[20];
    int i = 0;

    while (*expressao) {
        if (isspace(*expressao)) {
            expressao++;
            continue;
        }

        if (isdigit(*expressao) || 
           ((*expressao == '-' || *expressao == '+') && isdigit(*(expressao + 1)))) {
            int j = 0;
            while (*expressao && (isdigit(*expressao) || *expressao == '-'))
                token[j++] = *expressao++;
            token[j] = '\0';
            push(&p, atoi(token));
        }
        else if (eh_operador(*expressao)) {
            int b = pop(&p);
            int a = pop(&p);
            int resultado;

            switch (*expressao) {
                case '+': resultado = a + b; break;
                case '-': resultado = a - b; break;
                case '*': resultado = a * b; break;
                case '/':
                    if (b == 0) {
                        printf("Erro: divisão por zero!\n");
                        exit(1);
                    }
                    resultado = a / b;
                    break;
            }
            push(&p, resultado);
            expressao++;
        } else {
            printf("Erro: caractere inválido '%c'\n", *expressao);
            exit(1);
        }
    }

    return pop(&p);
}

int main() {
    const char* expressao = "3 4 + 2 *";
    int resultado = avaliar_posfixa(expressao);
    printf("Resultado: %d\n", resultado);
    return 0;
}
