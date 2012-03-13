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
	for(it1 = lista.begin(); it1 != lista.end(); it1++ ) {
		//cout << hex << *it1 <<" ";
		cout << *it1 <<" ";
	
	}
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
	/*
	for(it1 = L1.begin(); it1 != L1.end(); it1++ ) {
		cout << *it1 << " ";

	}
	cout << endl;

	for(it2 = L2.begin(); it2 != L2.end(); it2++ ) {
		cout << *it2 << " ";

	}
	cout << endl;
	*/

}

list <int> dodawanie(list <int> T1, list <int> T2) {
	int x=0;

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

list <int> mnozenie(list <int> T1, list <int> T2) {
	int i=0, x=0;

	list<list <int> > wiersze;
	
	for(rit1 = T1.rbegin(), i=0; rit1 != T1.rend(); rit1++, i++) {
		//wiersze.push_back(list<int>());
		list <int> tmp;
		
		for(rit2 = T2.rbegin(); rit2 != T2.rend(); rit2++) {
			x = *rit1 * *rit2 + x;
			tmp.push_front(x%10);
			x = x/10;
		}
		if(x!=0)
			tmp.push_front(x%10);
		
		x = 0;
		
		for(int j=0; j<i; j++)
			tmp.push_back(0);
		
		//drukuj(tmp);		
		
		wiersze.push_back(tmp);
		
	}
	
	/*wydrukujmy wiersze! a co!
	i=0;
	for(list <list <int> >::iterator iter = wiersze.begin(); iter != wiersze.end(); i++, iter++) {
			for(list <int>::iterator tip = iter->begin(); tip != iter->end(); tip++){
				cout << *tip<< " ";
				
					
			}
			cout <<endl;
	}
	*/

	list <int> pusty; 
	
	for(list <list <int> >::iterator iter = wiersze.begin(); iter != wiersze.end(); iter++) {	
		pusty = dodawanie(pusty, *iter);		
						
	}
	
	return pusty;
}

list <int> odejmowanie(list <int> T1, list <int> T2) { 
	int x=0, carry=0;
	list <int> wynik;

	list<int>::reverse_iterator tip;

	//cout<<"Odejmowanie..."<<endl;
	
	x = T1.size() - T2.size();

	for(int i=0; i < x; i++)
		T2.push_front(0);
	

	if(T1.size() == T2.size()) {
		for(rit1 = T1.rbegin(), rit2 = T2.rbegin(); 
			rit1!= T1.rend(), rit2 != T2.rend(); 
			rit1++, rit2++ ) {
				x = *rit1 - *rit2;

				x = x%10;
				if(x < 0) {
					x+=10;
					carry++;
				}

				if(carry > 0) {
					int i=0;

					//szukamy pozyczki
					for(tip = rit1; tip != T1.rend(); tip++) {
						if(*tip > 0 && i > 0) {
							*tip = *tip -1;
							break;
						}
						else
						{
							*tip = *tip -1;	
						}
						i++;
					}
				}

				wynik.push_front(x);
				carry=0;

		}

	}

	int ile_zer = 0;
	//usuwamy zera na przedzie
	for(it1 = wynik.begin(); it1 != wynik.end(); it1++) {
		if(*it1 == 0) {
			ile_zer++;
		}
		else {
			break;
		}
	}

	for(int i=0; i < ile_zer; i++)
		wynik.pop_front();

	return wynik;
}

char porownanie(list<int> T1, list<int> T2) {
	
	if(T1.size() > T2.size() ) 
		return '>';
	else if(T1.size() < T2.size() ) 
		return '<';
	else {
		//oba ciagi sa rowne...
		for(it1 = T1.begin(), it2 = T2.begin(); 
			it1!= T1.end(), it2 != T2.end(); 
			it1++, it2++ ) {
				if(*it1 < *it2)			
					return '<';
				
				if(*it1 > *it2)			
					return '>';
		}
		//przeszlismy obie listy -> rowne
		return '=';
	}

}

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

		L1.clear();
		L2.clear();
	}

	system("pause");
	return 0;
}