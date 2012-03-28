#include <iostream>
#include <list>
#include <string>

#define BAZA 256

using namespace std;

//globalne
list<int> L1, L2; //, wynik;
list<int>::iterator it1, it2;
list<int>::reverse_iterator rit1, rit2;

string liczba1, liczba2;
bool znak1 = false, znak2 = false, znak_wyniku =false;	//zakladamy ze wejsciowe stringi sa ujemne


list <int> odejmowanie(list <int> T1, list <int> T2);

//odnosze wra¿enie ¿e moznalo te funkcje napisac ladniej...
int hex2dec(char c) {
	//tablica ASCII
	if( (int)c >=48 && (int)c <= 57) {
        return (int)c - 48;
	}
	else {
		switch(c) {
			case 'A': return 10;
			case 'a': return 10;			
			case 'B': return 11;
			case 'b': return 11;
			case 'C': return 12;
			case 'c': return 12;
			case 'D': return 13;
			case 'd': return 13;
			case 'E': return 14;
			case 'e': return 14;
			case 'F': return 15;
			case 'f': return 15;

			default: return -1;
		}
	}
}

void drukuj(list <int> lista) {
	if(znak_wyniku)
		cout<< "-";

	for(it1 = lista.begin(); it1 != lista.end(); it1++ ) {
		if(*it1 < 16)
			cout << "0";
		
		cout << hex << *it1;
		//cout << *it1;
	
	}
	cout << endl;
}

void zamiana() {
	
	if(liczba1[0] == '-') {
		znak1 = true;		//ujemny...
		//cout<<"L1 ujemny\n";
		liczba1.erase(0,1);
	}
		
	if(liczba2[0] == '-') {
		znak2 = true;		//ujemny...
		//cout<<"L2 ujemny\n";
		liczba2.erase(0,1);
	}
	
	
	
	/*chcemy stringi parzystej dlugosci!
	if(!(liczba1.length() %2 == 0)) {
		liczba1 = "0" + liczba1;
		//cout << liczba1 <<endl;
	}
	if(!(liczba2.length() %2 == 0)) {
		liczba2 = "0" + liczba2;		
		//cout << liczba2 <<endl;
	}*/
		
	
	//tworzymy listy ze stringow
	for(unsigned int i=0; i < liczba1.length(); i=i+2) {
		L1.push_back(hex2dec(liczba1[i])*16 + 
		hex2dec(liczba1[i+1]));
	}

	//drukuj(L1);

	for(unsigned int i=0; i < liczba2.length(); i=i+2) {
		L2.push_back(hex2dec(liczba2[i])*16 + 
		hex2dec(liczba2[i+1]));
	}

	//drukuj(L2);
	
}

char porownanie(list<int> T1, list<int> T2) {
	
	//najpierw porownanie znakow...
	if(znak1 == true && znak2 == false) {
		return '<';
	}
	if(znak1 == false && znak2 == true) {
		return '>';
	}
	if(znak1 == true && znak2 == true) {
		//oba ciagi ujemne
		
	
	if(T1.size() > T2.size() ) 
		return '<';
	else if(T1.size() < T2.size() ) 
		return '>';
	else {
			
		for(it1 = T1.begin(), it2 = T2.begin(); 
			it1!= T1.end(), it2 != T2.end(); 
			it1++, it2++ ) {
				if(*it1 < *it2)			
					return '>';
				
				if(*it1 > *it2)			
					return '<';
		}
		}
		//przeszlismy obie listy -> rowne
		return '=';
	}
	
	
	
	
	
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

list <int> dodawanie(list <int> T1, list <int> T2) {
	int x=0;
	list <int> wynik;

	if(znak1 && znak2) {
		znak_wyniku = true;
		//a dalej normalne dodawanie
	}
	
	if(znak2) {
		znak2 = false;
		return odejmowanie(T1, T2);
	}
	
	//1 przypadek
	if(T1.size() == T2.size()) {
		for(rit1 = T1.rbegin(), rit2 = T2.rbegin();
			rit1 != T1.rend(), rit2 != T2.rend();
			rit1++, rit2++) {
				x = *rit1 + *rit2 + x;
				wynik.push_front(x%BAZA);
				x = x/BAZA;			
		}
		if(x!=0)
			wynik.push_front(x%BAZA);				
	}

		//2 przypadek
	if(T1.size() < T2.size()) {
		rit1 = T1.rbegin();
		rit2 = T2.rbegin();
		
		while( rit1 != T1.rend() ) {
			x = *rit1 + *rit2 + x;
			wynik.push_front(x%BAZA);
			x = x/BAZA;			
		
			rit1++, rit2++;
		}
		
		for(; rit2 != T2.rend(); rit2++) {
			x = *rit2 + x;
			wynik.push_front(x%BAZA);
			x = x/BAZA;								
		}
		if(x!=0)
			wynik.push_front(x%BAZA);				
		
	}
	
	//3 przypadek(analogicznie)
	if(T1.size() > T2.size()) {
		rit1 = T1.rbegin();
		rit2 = T2.rbegin();
				
		while( rit2 != T2.rend() ) {
			x = *rit1 + *rit2 + x;
			wynik.push_front(x%BAZA);
			x = x/BAZA;			
		
			rit1++, rit2++;
		}
		
		for(; rit1 != T1.rend(); rit1++) {
			x = *rit1 + x;
			wynik.push_front(x%BAZA);
			x = x/BAZA;								
		}
		if(x!=0)
			wynik.push_front(x%BAZA);				
		
	}

	return wynik;
}

list <int> mnozenie(list <int> T1, list <int> T2) {
	int i=0, x=0;

	if(znak1 || znak2) {
		znak_wyniku= true;
	}


	list<list <int> > wiersze;
	
	for(rit1 = T1.rbegin(), i=0; rit1 != T1.rend(); rit1++, i++) {
		//wiersze.push_back(list<int>());
		list <int> tmp;
		
		for(rit2 = T2.rbegin(); rit2 != T2.rend(); rit2++) {
			x = *rit1 * *rit2 + x;
			tmp.push_front(x%BAZA);
			x = x/BAZA;
		}
		if(x!=0)
			tmp.push_front(x%BAZA);
		
		x = 0;
		
		for(int j=0; j<i; j++)
			tmp.push_back(0);
		
		//drukuj(tmp);		
		
		wiersze.push_back(tmp);
		
	}
	
	/*wydrukujmy wiersze! a co!
	i=0;
	for(list <list <int> >::iterator iter = wiersze.begin(); iter != 
wiersze.end(); i++, iter++) {
			for(list <int>::iterator tip = iter->begin(); 
tip != iter->end(); tip++){
				cout << *tip<< " ";
				
					
			}
			cout <<endl;
	}
	*/

	list <int> pusty; 
	
	for(list <list <int> >::iterator iter = wiersze.begin(); iter != 
wiersze.end(); iter++) {	
		pusty = dodawanie(pusty, *iter);		
						
	}
	
	return pusty;
}

list <int> odejmowanie(list <int> T1, list <int> T2) { 
	int x=0, carry=0;
	list <int> wynik;
	list<int>::reverse_iterator tip;
	
	if(znak2 == true && znak1 == false) {
		znak2=false;
		znak1 = false;
		return dodawanie(T1,T2);
	
	}
	
	if(znak1 == true) {
		znak_wyniku = true;
		znak1 = false;
		znak2 = false;
		return dodawanie(T1, T2);
	}
	
	if(porownanie(T1, T2) == '<') {
		znak_wyniku = true;
		return odejmowanie(T2,T1);
		
	}
	
	x = T1.size() - T2.size();

	for(int i=0; i < x; i++)
		T2.push_front(0);
	

	if(T1.size() == T2.size()) {
		for(rit1 = T1.rbegin(), rit2 = T2.rbegin(); 
			rit1!= T1.rend(), rit2 != T2.rend(); 
			rit1++, rit2++ ) {
				x = *rit1 - *rit2 - carry;
				carry=0;
				x = x%BAZA;
				if(x < 0) {
					x+=BAZA;
					carry++;
				}
					
				wynik.push_front(x);
				//carry=0;

		}
		if(carry > 0) {
			it1 = wynik.begin();
			*it1 -= carry;
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


	//wynik moze byc rowny 0
	if(wynik.empty())
		wynik.push_back(0);
	
	return wynik;
}

list <int> dzielenie(list <int> T1, list <int> T2) {
	list <int> wynik;
	int i =0, x =0;
	list <int> nowy;
	list <int> tmp1, tmp2;

	it1 = T1.begin();
	it2 = T2.begin();

	while (it1 != T1.end()) {
		
		//naiwne...ile razy sie zmieœci?
		while(*it1 > 0) {
			*it1 -= *it2;
			i++;
		
		}
		nowy.push_back(i);
		i = x = 0;
		
		it1++;
	}

	drukuj(nowy);
	
	return wynik;
}


int main(int argc, char **argv) {
	char operacja;
		cin >> liczba1 >> operacja >> liczba2;
		zamiana();

		switch (operacja) {
			case '+': drukuj(dodawanie(L1, L2)); break;
		
			case '*': drukuj(mnozenie(L1,L2)); break;

			case '-': drukuj(odejmowanie(L1, L2)); break;

			case '/': drukuj(dzielenie(L1, L2)); break;

			
			case '?': cout << porownanie(L1,L2) << endl; 
		break;

			default:
				break;
		}

		//znak = false;
		L1.clear();
		L2.clear();

	return 0;
}
