#include<iostream>	
using namespace std;

typedef struct node
{
	int n;
	struct node* right;
	struct node* left;
}NODE;

class Tree
{
	public:NODE* gRoot;

	public:
		Tree();
		void addElement(int _n);
		NODE* getElement(NODE* current, int _n);
		void printPreorder(NODE* current); // koren - levy - pravy
		void printInorder(NODE* current);
		void printPostorder(NODE* current);
		NODE* findMin(NODE* current);
		NODE* getParent(NODE* current, int _n);
		void removeElement(NODE* gRoot, int _n);
		~Tree();
};
