#include <stdio.h>
#define MAX 10

int stack[MAX];
int top = -1;

void push(int value) {
    if (top >= MAX - 1)
        printf("Stack Overflow\n");
    else {
        stack[++top] = value;
        printf("%d pushed to stack\n", value);
    }
}

int pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return 0;
    } else {
        int value = stack[top--];
        return value;
    }
}

int peek() {
    if (top < 0) {
        printf("Stack is Empty\n");
        return 0;
    } else {
        return stack[top];
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    printf("%d popped from stack\n", pop());
    printf("Top element is %d\n", peek());
    return 0;
}
