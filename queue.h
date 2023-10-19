#pragma once
/**
 * Project: Data Structure Playground [Assignment]
 * File: "queue.h" : File contain function definitions for queue
 * Description: This project include a menu based system to perform various functions like add, delete, search and dislpay elements with various data structures, that including Linked List, Queue, and Stack.
 *
 * Author: Hamza Qureshi
 * Github: github.com/hamzaqureshi5
 * Email: hamza7771.861@gmail.com
 * Date: 18-10-2023
 */


#include <iostream>
using namespace std;

// Define a struct for a queue node
struct QueueNode 
{
    int data;
    QueueNode* next;

    QueueNode(int value) : data(value), next(nullptr) {}
    // alternative of this
    /*
    * node newnode= new Node()
    * newnode->data=0;
    * newnode->next=nullptr;
    */

};

class Queue 
{
private:
    QueueNode* front; // Pointer to the front of the queue
    QueueNode* rear;  // Pointer to the rear of the queue

public:
    // Constructor
    //Queue()
    //{
    //}
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor
    ~Queue() 
    {
        while (front) 
        {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    void enqueue(int value) 
    {
        QueueNode* newNode = new QueueNode(value);
        if (isEmpty()) 
        {
            front = rear = newNode;
        }
        else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to dequeue (remove) elements from the queue
    void dequeue() {
        if (isEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue.\n";
        }
        else {
            QueueNode* temp = front;
            front = front->next;
            delete temp;
        }
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Function to display the elements in the queue
    void display() {
        QueueNode* current = front;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    
    void QueueSearch(int value) 
    {
        QueueNode* current = front;
        bool found = false;

        while (current != nullptr) 
        {
            if (current->data == value) 
            {
                std::cout << "Element found" << std::endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) 
        {
            std::cout << "Element not found" << std::endl;
        }
    }
    void exec()
    {
        int element;
        unsigned char choice;
        while (true)
        {
            cout << "Queue Menu:" << endl;
            cout << "1. Insert element" << endl;
            cout << "2. Delete element" << endl;
            cout << "3. Search element" << endl;
            cout << "4. Display elements" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Enter element to insert: ";
                cin >> element;
                enqueue(element);
                cout << element << " inserted into the queue." << endl;
                break;
            case 2:
                if (!isEmpty())
                {
                    dequeue();
                    cout << "Element removed from the queue." << endl;
                }
                else {
                    cout << "Queue is empty. Cannot delete." << endl;
                }
                break;
            case 3:
                cout << "Enter element to insert: ";
                cin >> element;
                QueueSearch(element);
                break;
            case 4:
                cout << "Queue elements: ";
                display();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
            }
        }

    }
};