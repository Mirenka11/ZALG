#include<iostream>
using namespace std;

typedef struct node
{
	int n;
	struct node* next;
}NODE;


class Staq
{
	public:
	NODE* head;
	int size;
	
		Staq();
		int pop();
		int getSize();
		
		~Staq();
}; 

class Stack: public Staq
{
	public: 
		//Stack()
		void insert(int _n);
};

class Queue: public Staq
{
	public:
		//Queue()
		void insert(int _n);
};

