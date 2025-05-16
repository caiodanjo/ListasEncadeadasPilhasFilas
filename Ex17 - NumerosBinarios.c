#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char* data;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* head;
    Node* tail;
} Queue;

void initQueue(Queue* q) {
    q->head = q->tail = NULL;
}

void enqueue(Queue* q, const char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = strdup(value);
    newNode->next = NULL;

    if (q->tail == NULL) {
        q->head = q->tail = newNode;
    } else {
        q->tail->next = newNode;
        q->tail = newNode;
    }
}

char* dequeue(Queue* q) {
    if (q->head == NULL) return NULL;

    Node* temp = q->head;
    char* value = temp->data;

    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;

    free(temp);
    return value;
}

int isEmpty(Queue* q) {
    return q->head == NULL;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        char* s = dequeue(q);
        free(s);
    }
}

void generateBinary(int N) {
    Queue q;
    initQueue(&q);
    enqueue(&q, "1");

    for (int i = 0; i < N; i++) {
        char* current = dequeue(&q);
        printf("%s\n", current);

        char* s1 = (char*)malloc(strlen(current) + 2);
        char* s2 = (char*)malloc(strlen(current) + 2);

        sprintf(s1, "%s0", current);
        sprintf(s2, "%s1", current);

        enqueue(&q, s1);
        enqueue(&q, s2);

        free(s1);
        free(s2);
        free(current);
    }

    freeQueue(&q);
}

int main() {
    int N = 3;
    generateBinary(N);
    return 0;
}
