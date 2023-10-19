/**
 * Project: Data Structure Playground [Assignment]
 * File: "list.h" : File contain function definitions for linked list
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


struct LinkedListNode 
{
	int data;
	LinkedListNode* next;
};

class list 
{
private:
	LinkedListNode* head;

public:
	list() 
	{
		head = nullptr;
	}
	~list() 
	{
		while (head != nullptr)
		{
			LinkedListNode* temp = head;
			head = head->next;
			delete temp;
		}
	}

	void insertElement(int element) 
	{
		LinkedListNode* newNode = new LinkedListNode;
		newNode->data = element;
		newNode->next = head;
		head = newNode;
		std::cout << "Element inserted successfully." << std::endl;
	}

	bool deleteElement(int element) {
		LinkedListNode* current = head;
		LinkedListNode* prev = nullptr;

		while (current != nullptr) {
			if (current->data == element) {
				if (prev == nullptr) {
					head = current->next;
				}
				else {
					prev->next = current->next;
				}
				delete current;
				std::cout << "Element deleted successfully." << std::endl;
				return true;
			}
			prev = current;
			current = current->next;
		}

		std::cout << "Element not found in the linked list." << std::endl;
		return false;
	}

	bool searchElement(int element) {
		LinkedListNode* current = head;

		while (current != nullptr) {
			if (current->data == element) {
				std::cout << "Element found in the linked list." << std::endl;
				return true;
			}
			current = current->next;
		}

		std::cout << "Element not found in the linked list." << std::endl;
		return false;
	}

	void displayElements() {
		LinkedListNode* current = head;
		std::cout << "Elements in the linked list: ";
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}

	void exec()
	{
		int element;
		unsigned char choice;
//		linked_list m_linklist;

		while (true)
		{
			cout << "Linked List Menu:" << endl;
			cout << "1. Insert element" << endl;
			cout << "2. Delete element" << endl;
			cout << "3. Search element" << endl;
			cout << "4. Display elements" << endl;
			cout << "5. Back to main menu" << endl;
			cout << "Enter your choice: ";

			cin >> choice;

			if (choice == 1)
			{
				cout << "Enter the element to insert: ";
				cin >> element;
				insertElement(element);

			}
			else if (choice == 2)
			{
				cout << "Enter the element to delete: ";
				cin >> element;
				deleteElement(element);
			}
			else if (choice == 3)
			{
				cout << "Enter the element to Search: ";
				cin >> element;
				searchElement(element);
			}
			else if (choice == 4)
			{
				displayElements();
			}
			else if (choice == 5)
			{
				break;
			}
		}
	}

};



//int main()
//{
//
//	return 0;
//}