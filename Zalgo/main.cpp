#include "BigNumbers.h"

//using namespace std;


int main(int argc, char **argv) {
	char operacja;

	while(true) {
		cin >> liczba1 >> operacja >> liczba2;
		zamiana();

		switch (operacja) {
			case '+': drukuj(dodawanie(L1, L2)); break;
		
			case '*': drukuj(mnozenie(L1,L2)); break;

			case '-': drukuj(odejmowanie(L1, L2)); break;
	
			case '?': cout << porownanie(L1,L2) << endl; break;

			default:
				break;
		}

		znak = false;
		L1.clear();
		L2.clear();
	}

	//system("pause");
	return 0;
}