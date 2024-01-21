#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int top; // Variable to hold the top, initialized to -1 when the stack is empty
    int elements[100]; // Variable to hold the stack elements
} stack;

int size = 0; // Variable to check the current size of the stack

int peek(stack s) {
    if (s.top == -1) {
        return -1;
    } else {
        return s.elements[s.top];
    }
}

int push(stack& s, int value) {
    if (s.top == 99) {
        printf("Stack is full! \n");
        return -1;
    } else {
        s.top = s.top + 1;
        s.elements[s.top] = value;
        size = s.top + 1;
        return value;
    }
}

int pop(stack& s) {
    if (s.top == -1) {
        printf("Empty stack! \n");
        return -1;
    } else {
        int removed_value = s.elements[s.top];
        s.top = s.top - 1;
        size = s.top + 1;
        return removed_value;
    }
}

int printStack(stack s) {
    if (s.top == -1) {
        printf("Empty stack!! \n");
        return -1;
    } else {
        for (int i = 0; i <= s.top; i++) {
            printf("%d\n", s.elements[i]);
        }
        return 0;
    }
}

int main() {
    stack my_stack;
    my_stack.top = -1; // Initialize the top
    int navigator = 0;
    int to_add = 0;

    while (navigator != 4) {
        printf("Welcome to your stack! To view your stack, enter '1', to insert a value into your stack, enter '2', to remove the top of your stack, enter '3', and to exit, enter '4'\n");
        scanf("%d", &navigator);

        switch (navigator) {
            case 1:
                if (my_stack.top == -1) {
                    printf("Your stack is empty! \n");
                } else {
                    printf("You chose to view the stack!\n ");
                    printStack(my_stack);
                }
                break;

            case 2:
                printf("You chose to insert! Please insert the number below: \n");
                scanf("%d", &to_add);
                push(my_stack, to_add);
                break;

            case 3:
                printf("You chose to remove the top! Removing\n ");
                pop(my_stack);
                printStack(my_stack);
                break;

            case 4:
                printf("You chose to exit the stack! \n");
                break;

            default:
                printf("You did not provide a valid option! Please try again \n");
        }
    }
    return 0;
}
