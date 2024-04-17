#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

void enqueue(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued to queue\n", value);
}

int dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return 0;
    }
    Node* temp = front;
    int value = temp->data;
    front = front->next;
    if (front == NULL) {
        rear = NULL;
    }
    free(temp);
    return value;
}

int peek() {
    if (front == NULL) {
        printf("Queue is Empty\n");
        return 0;
    } else {
        return front->data;
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    printf("%d dequeued from queue\n", dequeue());
    printf("Front element is %d\n", peek());
    return 0;
}
