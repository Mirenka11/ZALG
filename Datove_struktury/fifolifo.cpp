
#include<iostream>
#include"fifolifo.h"
using namespace std;

Staq::Staq()
{
	head = new NODE;
	head->n = 0;
	head->next = nullptr;
	size = 0;
}

void Stack::insert(int _n) //lifo
{
	NODE* newNode = new NODE;
	newNode->n = _n;
	newNode->next = head;
	head = newNode;
	size++;	
}

void Queue::insert(int _n) //fifo
{
	NODE* newNode = new NODE;
	newNode->n = _n;
	newNode->next = nullptr;
	NODE* current = head;
	if (size == 0)
		head = newNode;
	while(current->next != nullptr)
		current = current->next;
	current->next = newNode;
	size++;
}

int Staq::pop()
{
	NODE* current = new NODE;
	current = head;
	head = current->next;
	int value = current->n;
	delete current;
	size--;
	return value;
}

int Staq::getSize()
{
	return size;
}

Staq::~Staq()
{
	NODE* current = new NODE;
	if(head != nullptr)
	{
		while(head->next != nullptr)
		{
			while(head->next->next != nullptr)
			{
				current = head->next;
				head->next = head->next->next;
				delete current;
			}
			delete head->next;
		}
		delete head;
	}
}


int main()
{
	Queue fronta = Queue();
	Stack zasobnik = Stack();

	fronta.insert(1);
	fronta.insert(2);
	fronta.insert(3);
	fronta.insert(4);
	fronta.insert(5);

	zasobnik.insert(1);
	zasobnik.insert(2);
	zasobnik.insert(3);
	zasobnik.insert(4);
	zasobnik.insert(5);

	cout << "FIFO:" << endl;
	while(fronta.getSize() != 0)
		cout << fronta.pop() << ", ";
	cout << endl;

	cout << "LIFO:" << endl;
	while(zasobnik.getSize() != 0)
		cout << zasobnik.pop() << ", ";
	cout << endl;
	

	return 0;	
}
