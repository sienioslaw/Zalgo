#include <iostream>
#include <list>
#include <string>
using namespace std;

//globalne
list<int> L1, L2; //, wynik;
list<int>::iterator it1, it2;
list<int>::reverse_iterator rit1, rit2;

string liczba1, liczba2;

//odnosze wra¿enie ¿e moznalo te funkcje napisac ladniej...
int hex2dec(char c) {
	//tablica ASCII
	if( (int)c >=48 && (int)c <= 57) {
        return (int)c - 48;
	}
	else {
		switch(c) {
			case 'A': return 10;
			case 'B': return 11;
			case 'C': return 12;
			case 'D': return 13;
			case 'E': return 14;
			case 'F': return 15;

			default: return -1;
		}
	}
}

void drukuj(list<int> lista) {
	for(it = lista.begin(); it != lista.end(); ++it )
		cout << hex << *it<<" ";
	
	cout << endl;
}


void zamiana() {
	/*
	//chcemy stringi parzystej dlugosci!
	if(!(liczba1.length() %2 == 0)) {
		liczba1 = "0" + liczba1;
		cout << liczba1 <<endl;
	}
	if(!(liczba2.length() %2 == 0)) {
		liczba2 = "0" + liczba2;		
		cout << liczba2 <<endl;
	}
	

	//tworzymy listy ze stringow
	for(int i=0; i < liczba1.length(); i=i+2) {
		L1.push_back(hex2dec(liczba1[i])*16 + hex2dec(liczba1[i+1]));
	}

	drukuj(L1);

	for(int i=0; i < liczba1.length(); i=i+2) {
		L1.push_back(hex2dec(liczba1[i])*16 + hex2dec(liczba1[i+1]));
	}

	drukuj(L2);
	*/

	for(int i=0; i< liczba1.length(); i++) {
		L1.push_back((int)liczba1[i]-48);
	}

	for(int i=0; i< liczba2.length(); i++) {
		L2.push_back((int)liczba2[i]-48);
	}
	
	for(it1 = L1.begin(); it1 != L1.end(); it1++ ) {
		cout << *it1 << " ";

	}
	cout << endl;

	for(it2 = L2.begin(); it2 != L2.end(); it2++ ) {
		cout << *it2 << " ";

	}
	cout << endl;


}

int main(int argc, char **argv) {
	
	cout << "Podaj I liczbe: ";
	cin >> liczba1;

	cout << "Podaj II liczbe: ";
	cin >> liczba2;

	zamiana();
	

	system("pause");
	return 0;
}