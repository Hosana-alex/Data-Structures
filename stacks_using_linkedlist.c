#include <stdio.h>
#include <stdlib.h>

typedef struct Node { //typedef is important
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return 0;
    }
    Node* temp = top;
    int popped = temp->data;
    top = top->next;
    free(temp);
    return popped;
}

int peek() {
    if (!top) {
        printf("Stack is Empty\n");
        return 0;
    }
    return top->data;
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("%d popped from stack\n", pop());
    printf("Top element is %d\n", peek());
    return 0;
}
