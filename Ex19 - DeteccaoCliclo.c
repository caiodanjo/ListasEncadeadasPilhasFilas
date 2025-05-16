#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

int detectar_ciclo(Node* head) {
    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;
        }
    }

    return 0;
}

int main() {
    Node* a = (Node*)malloc(sizeof(Node));
    Node* b = (Node*)malloc(sizeof(Node));
    Node* c = (Node*)malloc(sizeof(Node));
    Node* d = (Node*)malloc(sizeof(Node));

    a->data = 1; a->next = b;
    b->data = 2; b->next = c;
    c->data = 3; c->next = d;
    d->data = 4; d->next = b;
    
    if (detectar_ciclo(a))
        printf("Ciclo detectado!\n");
    else
        printf("Nenhum ciclo.\n");

    return 0;
}
