#include<iostream>	
#include"strom.h"
using namespace std;

Tree::Tree()
{
	gRoot = new NODE;
	gRoot->n = 0;
	gRoot->right = nullptr;
	gRoot->left = nullptr;
}

void Tree::addElement(int _n) 
{
	//TODO bylo by k něčemu udělat o taky rekurzí??? 
	
	/*Vytvoreni noveho uzloveho bodu*/
	NODE* newNode = new NODE;
	newNode->n = _n;
	newNode->right = nullptr;
	newNode->left = nullptr;
	/*------------------------------*/
	if(gRoot->n == 0)
		gRoot = newNode; // vkladani do prazdneho stromu
	else
	{
		NODE* current = new NODE;
		current = gRoot;
		while (current->right != nullptr && current->left != nullptr)
		{
			if (_n > current->n)
				current = current->right;
			else current = current->left;
		}
		if (_n > current->n)
			current->right = newNode;
		else current->left = newNode;
	}
}
NODE* Tree::getElement(NODE* current, int _n)
{
	if(current->n == _n)
		return current;
	
	if(_n > current->n && current->right != nullptr)
	{
		getElement(current->right, _n);
	//	cout << "right" << endl;
	}
		
	else if(_n < current->n && current->left != nullptr)
	{
		getElement(current->left, _n);
	//	cout << "left" << endl;
	}
	
	else return nullptr;
}
void Tree::printPreorder(NODE* current) // koren - levy - pravy
{
	// nemam rada rekurze, ale tady si to o ni rika... :( 
    if (current == NULL)
        return;
    cout << current->n << " ";
    printPreorder(current->left);
    printPreorder(current->right);
}

void Tree::printInorder(NODE* current)
{
	if (current == NULL)
        return;
    printInorder(current->left);
    cout << current->n << " ";
    printInorder(current->right);
}
void Tree::printPostorder(NODE* current)
{
	if (current == NULL)
        return;
    printPostorder(current->left);
    printPostorder(current->right);
    cout << current->n << " ";
}

NODE* Tree::getParent(NODE* current, int _n)
{
	if (current->n == _n) return nullptr;
	/*	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 	DŮLEŽITÝ PŘEDPOKLAD: _n JE PRVKEM BINÁRNÍHO STROMU	
	 	!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 */
	 while(current->left->n != _n && current->right->n != _n)
	 {
	 	// TODO
	 }



}

NODE* Tree::findMin(NODE* current)
{
	while(current->left != nullptr)
		current = current->left;
	return current;
}
void Tree::removeElement(NODE* gRoot, int _n)
{
	NODE* current = getElement(gRoot, _n); // tohle chci smazat
	
	if(current->right == nullptr || current->left == nullptr)
	/*strom pokračuje nejvýše jedním směrem -- prvek který chci smazat nahradím jeho levým/pravým následovníkem (jasně že tím, který není prázdný). 
	pokud strom nepokračuje, můžu prvek beztrestně smazat*/
	{
		if(current->left != nullptr) //můžu jít doleva
		{
			NODE* nahradnik = getParent(current, _n);
			// ověřit jestli nahradnik neni nullptr
			// nahradit co je potřeba
		}
		else if(current->right != nullptr) // můžu jít doleva
		{	
			NODE* nahradnik = getParent(current, _n);
			//TODO
		}
		else delete current;
	}
	 
	else //*odstraňovaný uzel pokračuje na obě strany -- nahradím jej hodnotou nejmenšího prvku v jeho pravém podstromu a mělo by to být OK
	{
		NODE* nahradnik = findMin(current->right);
		current->n = nahradnik->n;
		delete nahradnik;
	}	
}
Tree::~Tree()
{
	//TODO
	//aby se Valgrind nezbláznil
}


int main()
{
	Tree binarniStrom = Tree();
	binarniStrom.addElement(50);
	binarniStrom.addElement(10);
	binarniStrom.addElement(70);
	binarniStrom.addElement(15);
	binarniStrom.addElement(65);
	binarniStrom.addElement(5);
	/*
				  50
			   /     \
			  10      70
			 /  \    /  \
			5   15 65   
	
	
	*/
	
	binarniStrom.printPreorder(binarniStrom.gRoot);
	cout << endl;
	
	
/* ================= Debugging goes BRRRRRRRRRRR ===================*/
	if(binarniStrom.getElement(binarniStrom.gRoot, 50))
		cout << "50 - OK" << endl;
	if(binarniStrom.getElement(binarniStrom.gRoot, 10))
		cout << "10 - OK" << endl;
	if(binarniStrom.getElement(binarniStrom.gRoot, 70))
		cout << "70 - OK" << endl;
	if(binarniStrom.getElement(binarniStrom.gRoot, 15))
		cout << "15 - OK" << endl;
	if(binarniStrom.getElement(binarniStrom.gRoot, 65))
		cout << "65 - OK" << endl;
	if(binarniStrom.getElement(binarniStrom.gRoot, 5))
		cout << "5 - OK" << endl;
	
	cout << endl;	
		
	if(!binarniStrom.getElement(binarniStrom.gRoot, 3))
		cout << "3 - OK" << endl;
	if(!binarniStrom.getElement(binarniStrom.gRoot, 7))
		cout << "7 - OK" << endl;
	if(!binarniStrom.getElement(binarniStrom.gRoot, 13))
		cout << "13 - OK" << endl;
	if(!binarniStrom.getElement(binarniStrom.gRoot, 25))
		cout << "25 - OK" << endl;
	if(!binarniStrom.getElement(binarniStrom.gRoot, 60))
		cout << "60 - OK" << endl;
	if(!binarniStrom.getElement(binarniStrom.gRoot, 69))
		cout << "69 - OK" << endl;
	if(!binarniStrom.getElement(binarniStrom.gRoot, 420))
		cout << "420 - OK" << endl;
		
	cout << endl;
		
	
	binarniStrom.removeElement(binarniStrom.gRoot, 10);
	binarniStrom.printPreorder(binarniStrom.gRoot);
	cout << endl;
	
	binarniStrom.removeElement(binarniStrom.gRoot, 15);
	binarniStrom.printPreorder(binarniStrom.gRoot);
	cout << endl;
	
	binarniStrom.removeElement(binarniStrom.gRoot, 70);
	binarniStrom.printPreorder(binarniStrom.gRoot);
	cout << endl;
	
	binarniStrom.removeElement(binarniStrom.gRoot, 65);
	binarniStrom.printPreorder(binarniStrom.gRoot);
	cout << endl;
	
	binarniStrom.removeElement(binarniStrom.gRoot, 50);
	binarniStrom.printPreorder(binarniStrom.gRoot);
	cout << endl;

 






	return 0;
}
