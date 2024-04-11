#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* top;
} Stack;

void initializeStack(Stack *s) {
    s->top = NULL;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

void push(Stack *s, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty\n");
        return -1; 
    }
    Node* temp = s->top;
    int popped = temp->data;
    s->top = temp->next;
    free(temp);
    return popped;
}

void printStack(Stack *s) {
    Node* temp = s->top;
    printf("Stack elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    Stack s;
    initializeStack(&s);

    printf("Pushing 10, 20, 30 into the stack...\n");
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printStack(&s);

    printf("Popping...\n");
    while (!isEmpty(&s)) {
        printf("%d popped from stack\n", pop(&s));
    }

    printf("Trying to pop from an empty stack...\n");
    int data = pop(&s);
    if(data == -1) {
        printf("Stack is empty. No elements to pop.\n");
    }

    return 0;
}