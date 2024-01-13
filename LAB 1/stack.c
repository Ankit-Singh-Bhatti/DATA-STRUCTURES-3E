#include<stdio.h>
#include<conio.h>

#define MAX_SIZE 50

int stack[MAX_SIZE], top = -1;

void push(int ele) {
    if (top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
    } else {
        top++;
        stack[top] = ele;
        printf("Element %d pushed to the stack\n", ele);
    }
}

void pop() {
    if (top == -1) {
        printf("Stack Underflow\n");
    } else {
        printf("Element %d popped from the stack\n", stack[top]);
        top--;
    }
}

void display() {
    if (top == -1) {
        printf("Stack is empty\n");
    } else {
        printf("Displaying the stack: ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int peek() {
    if (top == -1) {
        printf("Stack is empty\n");
        return -1; // indicating an error value
    } else {
        return stack[top];
    }
}

int main() {
    int choice, ele;

    do {
        printf("\n1. Push\n2. Pop\n3. Display\n4. Peek\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf("%d", &ele);
                push(ele);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                ele = peek();
                if (ele != -1) {
                    printf("Top element of the stack: %d\n", ele);
                }
                break;
            case 5:
                printf("Exiting the program\n");
                break;
            default:
                printf("Invalid choice\n");
        }

    } while (choice != 5);

    return 0;
}

