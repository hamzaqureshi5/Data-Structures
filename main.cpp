/*
 *
 * Project: Data Structure Playground [Assignment]
 * Description: This project include a menu based system to perform various functions like add, delete, search and dislpay elements with various data structures, that including Linked List, Queue, and Stack.
 *
 * Author: Hamza Qureshi
 * Github: github.com/hamzaqureshi5
 * Email: hamza7771.861@gmail.com
 * Date: 18-10-2023
 *
 */


#include <iostream>
#include "list.h"
#include "queue.h"
#include "stack.h"
using namespace std;

int main()
{

	while (true)
	{
		cout << "#========================================#" << endl;
		cout << "  Welcome to the Data Structure Console!" << endl;
		cout << "#========================================#" << endl;

		cout << "1. Linked List" << endl;
		cout << "2. Queue" << endl;
		cout << "3. Stack" << endl;
		cout << "4. Exit" << endl;
		cout << "Enter your choice: ";

		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			list m_list;
			m_list.exec();
			break;
		}
		case 2:
		{
			Queue m_queue;
			m_queue.exec();
			break;
		}

		case 3:
		{
			Stack m_stack;
			m_stack.exec();
			break;
		}
		case 4:
		{
			exit(0);
		}
		default:
		{
			break;
		}
	}
}
	return 0;
}