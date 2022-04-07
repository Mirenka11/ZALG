using namespace std;

class Graf
{
	int n;
	double** cesty;

	public:	
		Graf(int _n);
		void novaCesta(int start, int cil, double delka);
		double najdiCestu(int start, int cil);
		void display();
		~Graf();
};
