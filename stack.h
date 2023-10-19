/**
 * Project: Data Structure Playground [Assignment]
 * File: "stack.h" : File contain function definitions for stacks
 * Description: This project include a menu based system to perform various functions like add, delete, search and dislpay elements with various data structures, that including Linked List, Queue, and Stack.
 *
 * Author: Hamza Qureshi
 * Github: github.com/hamzaqureshi5
 * Email: hamza7771.861@gmail.com
 * Date: 18-10-2023
 */

#pragma once

#include <iostream>
using namespace std;

// Define a struct for a stack node
struct Node 
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {} //Initialized

    // alternative of this
    /*
    * node newnode= new Node()
    * newnode->data=0;
    * newnode->next=nullptr;        
    */
};

class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    // Constructor
    Stack() : top(nullptr) {}

    // Destructor
    ~Stack() {
        while (top) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to push elements onto the stack
    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop elements from the stack
    void pop() {
        if (isEmpty()) {
            std::cout << "Stack is empty. Cannot pop." << std::endl;
        }
        else {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    // Function to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Function to display the elements in the stack
    void display() {
        Node* current = top;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void exec()
    {
        int element;
        unsigned char choice;
        while (true)
        {
            cout << "Stack Menu:" << endl;
            cout << "1. Push element" << endl;
            cout << "2. Pop element" << endl;
            cout << "3. Display elements" << endl;
            cout << "4. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                cout << "Enter element to push: ";
                cin >> element;
                push(element);
                cout << element << " pushed onto the stack." << endl;
                break;
            case 2:
                if (!isEmpty()) {
                    pop();
                    cout << "Element popped from the stack." << endl;
                }
                else {
                    cout << "Stack is empty. Cannot pop." << endl;
                }
                break;
            case 3:
                cout << "Stack elements: ";
                display();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }

    }
};

