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
	for(it1 = lista.begin(); it1 != lista.end(); it1++ )
		cout << hex << *it1 <<" ";
	
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

list <int> dodawanie(list <int> T1, list <int> T2) {
	int x=0;

	cout<<"Dodawanie..."<<endl;
	list <int> wynik;


	//1 przypadek
	if(T1.size() == T2.size()) {
		for(rit1 = T1.rbegin(), rit2 = T2.rbegin();
			rit1 != T1.rend(), rit2 != T2.rend();
			rit1++, rit2++) {
				x = *rit1 + *rit2 + x;
				wynik.push_front(x%10);
				x = x/10;			
		}
		if(x!=0)
			wynik.push_front(x%10);				
	}

		//2 przypadek
	if(T1.size() < T2.size()) {
		rit1 = T1.rbegin();
		rit2 = T2.rbegin();
		
		while( rit1 != T1.rend() ) {
			x = *rit1 + *rit2 + x;
			wynik.push_front(x%10);
			x = x/10;			
		
			rit1++, rit2++;
		}
		
		for(rit2; rit2 != T2.rend(); rit2++) {
			x = *rit2 + x;
			wynik.push_front(x%10);
			x = x/10;								
		}
		if(x!=0)
			wynik.push_front(x%10);				
		
	}
	
	//3 przypadek(analogicznie)
	if(T1.size() > T2.size()) {
		rit1 = T1.rbegin();
		rit2 = T2.rbegin();
				
		while( rit2 != T2.rend() ) {
			x = *rit1 + *rit2 + x;
			wynik.push_front(x%10);
			x = x/10;			
		
			rit1++, rit2++;
		}
		
		for(rit1; rit1 != T1.rend(); rit1++) {
			x = *rit1 + x;
			wynik.push_front(x%10);
			x = x/10;								
		}
		if(x!=0)
			wynik.push_front(x%10);				
		
	}

	return wynik;
}

int main(int argc, char **argv) {
	
	cout << "Podaj I liczbe: ";
	cin >> liczba1;

	cout << "Podaj II liczbe: ";
	cin >> liczba2;

	zamiana();
	drukuj(dodawanie(L1,L2));

	system("pause");
	return 0;
}