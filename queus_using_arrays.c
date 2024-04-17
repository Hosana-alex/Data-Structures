#include <stdio.h>
#define MAX 10

int queue[MAX];
int front = 0;
int rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1)
        printf("Queue Overflow\n");
    else {
        queue[++rear] = value;
        printf("%d enqueued to queue\n", value);
    }
}

int dequeue() {
    if (front > rear) {
        printf("Queue Underflow\n");
        return 0;
    } else {
        int value = queue[front++];
        return value;
    }
}

int peek() {
    if (front > rear) {
        printf("Queue is Empty\n");
        return 0;
    } else {
        return queue[front];
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
