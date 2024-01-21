#include <iostream>
using namespace std;

typedef struct Node {
    int data;
    Node* next;
} Node;

typedef struct Stack {
    int top;
    Node* head;
} Stack;

void initialize(Stack* s) {
    s->head = NULL;
    s->top = -1;
}

void push(Stack* s, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = s->head;
    s->head = newNode;
    s->top++;
}

int pop(Stack* s) {
    if (s->top == -1) {
        cout << "Stack is empty!\n";
        return -1;
    }

    int value = s->head->data;
    Node* toRemove = s->head;
    s->head = s->head->next;
    delete toRemove;
    s->top--;

    return value;
}

void printStack(Stack* s) {
    Node* current = s->head;
    cout << "Stack: ";
    while (current != NULL) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Stack my_stack;
    initialize(&my_stack);

    int navigator = 0;
    int to_add = 0;

    while (true) {
        cout << "Welcome to your stack! To view your stack, enter '1', to insert a value into your stack, enter '2', to remove the top of your stack, enter '3', and to exit, enter '4'\n";
        cin >> navigator;

        switch (navigator) {
            case 1:
                if (my_stack.top == -1) {
                    cout << "Your stack is empty! \n";
                } else {
                    cout << "You chose to view the stack!\n ";
                    printStack(&my_stack);
                }
                break;

            case 2:
                cout << "You chose to insert! Please insert the number below: \n";
                cin >> to_add;
                push(&my_stack, to_add);
                break;

            case 3:
                if (my_stack.top == -1) {
                    cout << "Stack is empty! \n";
                } else {
                    cout << "You chose to remove the top! Removing " << my_stack.head->data << "\n ";
                    pop(&my_stack);
                    printStack(&my_stack);
                }
                break;

            case 4:
                cout << "You chose to exit the stack! \n";
                return 0;

            default:
                cout << "You did not provide a valid option! Please try again \n";
        }
    }
    return 0;
}
