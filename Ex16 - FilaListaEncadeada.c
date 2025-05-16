#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* q) {
    q->head = NULL;
    q->tail = NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro de alocação de memória.\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

int dequeue(Queue* q) {
    if (q->head == NULL) {
        printf("Fila vazia.\n");
        return -1;
    }

    Node* temp = q->head;
    int value = temp->data;

    q->head = q->head->next;
    if (q->head == NULL) {
        q->tail = NULL;
    }

    free(temp);
    return value;
}

int isEmpty(Queue* q) {
    return q->head == NULL;
}

void printQueue(Queue* q) {
    Node* current = q->head;
    printf("Fila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Queue q;
    initQueue(&q);

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    printQueue(&q);

    printf("Removido: %d\n", dequeue(&q));
    printQueue(&q);

    return 0;
}
