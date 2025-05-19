#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int calcular_agua_retida(int* altura, int tamanho) {
    if (tamanho == 0) return 0;

    int pilha[MAX];
    int topo = -1;
    int agua = 0, atual = 0;

    while (atual < tamanho) {
        while (topo >= 0 && altura[atual] > altura[pilha[topo]]) {
            int fundo = pilha[topo--];

            if (topo < 0) break;

            int distancia = atual - pilha[topo] - 1;
            int altura_agua = (altura[atual] < altura[pilha[topo]] ? altura[atual] : altura[pilha[topo]]) - altura[fundo];
            agua += distancia * altura_agua;
        }

        pilha[++topo] = atual++;
    }

    return agua;
}

int main() {
    int altura[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    int tamanho = sizeof(altura)/sizeof(altura[0]);

    int resultado = calcular_agua_retida(altura, tamanho);
    printf("Água retida: %d\n", resultado);

    return 0;
}
