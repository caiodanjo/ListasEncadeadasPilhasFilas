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
    q->head = q->tail = NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
    if (q->head == NULL) return -1;

    Node* temp = q->head;
    int value = temp->data;

    q->head = q->head->next;
    if (q->head == NULL) q->tail = NULL;

    free(temp);
    return value;
}

int isEmptyQueue(Queue* q) {
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

typedef struct StackNode {
    int data;
    struct StackNode* next;
} StackNode;

typedef struct Stack {
    StackNode* top;
} Stack;

void initStack(Stack* s) {
    s->top = NULL;
}

void push(Stack* s, int value) {
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack* s) {
    if (s->top == NULL) return -1;

    StackNode* temp = s->top;
    int value = temp->data;
    s->top = s->top->next;
    free(temp);
    return value;
}

int isEmptyStack(Stack* s) {
    return s->top == NULL;
}

void inverter_primeiros_k(Queue* q, int k) {
    if (k <= 0 || q->head == NULL) return;

    Stack s;
    initStack(&s);

    for (int i = 0; i < k && !isEmptyQueue(q); i++) {
        push(&s, dequeue(q));
    }

    while (!isEmptyStack(&s)) {
        enqueue(q, pop(&s));
    }

    int n = 0;
    Node* temp = q->head;
    while (temp != NULL) {
        n++;
        temp = temp->next;
    }

    for (int i = 0; i < n - k; i++) {
        enqueue(q, dequeue(q));
    }
}

int main() {
    Queue q;
    initQueue(&q);

    for (int i = 1; i <= 7; i++) {
        enqueue(&q, i);
    }

    printf("Fila original:\n");
    printQueue(&q);

    int k = 4;
    inverter_primeiros_k(&q, k);

    printf("Fila após inverter os %d primeiros elementos:\n", k);
    printQueue(&q);

    return 0;
}
