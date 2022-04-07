#include <iostream>
#include "graf.h"
using namespace std;

	Graf::Graf(int _n)
{
	n = _n;
	cesty = new double*[n];
	for (int i = 0; i < n; i++)
	{
		cesty[i] = new double[n];
		for (int j = 0; j < n; j++)
			cesty[i][j] = 0;
	}
}

void Graf::novaCesta(int start, int cil, double delka)
{
	cesty[start][cil] = delka;
	// pro odebrani cesty staci nastavit jeji delku na 0
}

double Graf::najdiCestu (int start, int cil)
{
	return cesty[start][cil];
}
void Graf::display()
{
	cout << "  " << '|' <<'\t';
	for (int i = 0; i < n; i++)
		cout << i << '\t';
	cout << endl;
	for (int i = 0; i < 9*n; i++)
		cout << "-";
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << i << " |" <<'\t';
		for (int j = 0; j < n; j++)
			cout << cesty[i][j] << '\t';  
		cout << endl;
	}
	for (int i = 0; i < 9*n; i++)
		cout << "-";
	cout << endl;
}

Graf::~Graf()
{
	for (int i = 0; i < n; i++)
		delete[] cesty[i];				
	delete[] cesty;
}

int main()
{
	int _n = 5;
	Graf novyGraf = Graf(_n);
	novyGraf.novaCesta(0, 1, 0.1);
	novyGraf.novaCesta(1, 3, 1.3);
	novyGraf.novaCesta(2, 1, 2.1);
	novyGraf.novaCesta(3, 2, 3.2);
	novyGraf.novaCesta(3, 4, 3.4);

	novyGraf.display();

	cout << novyGraf.najdiCestu(0,1)<< endl;
	cout << novyGraf.najdiCestu(1,3)<< endl;
	cout << novyGraf.najdiCestu(2,1)<< endl;
	cout << novyGraf.najdiCestu(3,2)<< endl;
	cout << novyGraf.najdiCestu(3,4)<< endl;
	cout << novyGraf.najdiCestu(2,3)<< endl;
	

	return 0; 
}

