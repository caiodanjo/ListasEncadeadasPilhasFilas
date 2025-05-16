#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* criar_no(int valor) {
    Node* novo = (Node*)malloc(sizeof(Node));
    novo->data = valor;
    novo->next = NULL;
    return novo;
}

Node* unir_listas_ordenadas(Node* l1, Node* l2) {
    Node dummy;
    dummy.next = NULL;
    Node* tail = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data < l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) tail->next = l1;
    if (l2 != NULL) tail->next = l2;

    return dummy.next;
}

void imprimir_lista(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* l1 = criar_no(1);
    l1->next = criar_no(3);
    l1->next->next = criar_no(5);

    Node* l2 = criar_no(2);
    l2->next = criar_no(4);
    l2->next->next = criar_no(6);

    printf("Lista 1: ");
    imprimir_lista(l1);
    printf("Lista 2: ");
    imprimir_lista(l2);

    Node* unida = unir_listas_ordenadas(l1, l2);
    printf("Lista unida: ");
    imprimir_lista(unida);

    return 0;
}
