#include <stdio.h>

#define STACK_SIZE 10

int n = STACK_SIZE, top = -1, stack[STACK_SIZE];

void push(int x) {
    if (top == n - 1) {
        printf("Stack overflow: Unable to push %d\n", x);
        return;
    }

    top = top + 1;
    stack[top] = x;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow: Unable to pop\n");
        return -1;
    }

    return stack[top--];
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = top; i > -1; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n\n");
}

int main() {
    printf("Initializing the stack with size %d\n\n", n);

    printf("Pushing elements into the stack\n");
    push(1);
    push(2);
    push(3);
    printf("\n");

    printf("Displaying elements of the stack\n");
    display();

    printf("Pop the top of the stack = %d\n", pop());
    printf("Pop the top of the stack = %d\n\n", pop());

    printf("Displaying elements of the stack\n");
    display();

    return 0;
}
