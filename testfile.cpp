#include <iostream>

using namespace std;

#define MAX_SIZE 10  // Define the upper limit of the stack

// Function to initialize the stack
void CreateStack(int &top) {
    top = -1;  // Set top to -1 to indicate an empty stack
}

// Function to push an item onto the stack
void push(int stack[], int item, int size, int &top) {
    if (top < size - 1) {
        top++;
        stack[top] = item;
        cout << "Pushed " << item << " onto the stack.\n";
    } else {
        cout << "Stack Overflow\n";  // Error when stack is full
    }
}

// Function to pop an item from the stack
int pop(int stack[], int &top) {
    if (top == -1) {
        cout << "Stack Underflow\n";  // Error when stack is empty
        return -1;
    } else {
        int del_val = stack[top];
        top--;
        cout << "Popped " << del_val << " from the stack.\n";
        return del_val;
    }
}

// Main function to test the stack operations
int main() {
    int stack[MAX_SIZE];  // Declare the stack array
    int top;  // Declare the top index

    CreateStack(top);  // Initialize the stack

    push(stack, 10, MAX_SIZE, top);
    push(stack, 20, MAX_SIZE, top);
    push(stack, 30, MAX_SIZE, top);

    pop(stack, top);
    pop(stack, top);
    pop(stack, top);
    pop(stack, top);  // This will trigger Stack Underflow

    return 0;
}


