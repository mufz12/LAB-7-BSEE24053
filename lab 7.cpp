// lab 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = NULL;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << "Value " << value << " pushed onto stack.\n";
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty, nothing to pop.\n";
            return;
        }

        Node* temp = top;
        cout << "Popped value: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty.\n";
        }
        else {
            cout << "Top of stack: " << top->data << endl;
        }
    }
};

int main() {
    Stack s;
    int choice, value;

    do {
        cout << "\n---- STACK MENU ----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty.\n";
            else
                cout << "Stack has elements.\n";
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid option, please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
