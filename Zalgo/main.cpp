#include "Big.h"
#include <cstdlib>
#include <time.h>
int poz1 = 0, poz2 = 0, pozw=0;
bool znak1 = false, znak2 = false, znak_wyniku =false;	//zakladamy ze wejsciowe stringi sa ujemne


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
	int i=0;
	for(it1 = lista.begin(); it1 != lista.end(); it1++ ) {
		if(pozw != 0 && i==pozw){
			cout<<"_";
		}

		if(*it1 < 16 && it1 != lista.begin())
			cout << "0";
		
		cout << hex << *it1;
		//cout << *it1;
		i++;
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
	
	//szukamy znakow
	for(unsigned int i=0; i< liczba1.length(); i++) {
		if(liczba1[i] == '_') { 
			poz1 = i;
			liczba1.erase(i,1);
			break;
		}
	}
	for(unsigned int i=0; i< liczba2.length(); i++) {
		if(liczba2[i] == '_') { 
			poz2 = i;
			liczba2.erase(i,1);
			break;
		}
	}
	
	poz1 = poz1/2;
	poz2 = poz2/2;
			
	
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

	if(znak1==true && znak2==true) {
		znak_wyniku = true;
		//a dalej normalne dodawanie
	}
	
	if(znak2) {
		znak2 = false;
		return odejmowanie(T1, T2);
	}

	if(znak1 && !znak2) {
		znak1 = false;
		znak2 = false;
		
		if(porownanie(T1,T2) == '>') {
			znak_wyniku = true;
			return odejmowanie(T1, T2);
	
		}
		
		if(porownanie(T1,T2) == '<') {
			//znak_wyniku = true;
			return odejmowanie(T2, T1);
	
		}
	}
	
		//liczby wymierne
	if(poz1!=0 || poz2!=0) {
		//oba maja znak
		list<int> ax, ay, bx, by;
		int i = 0;

		if(poz1 !=0) {
			for(it1=T1.begin(), i = 1 ; it1 != T1.end(); it1++) {
				if(i <= poz1) {
					ax.push_back(*it1);
				}
				if(i > poz1) {
					ay.push_back(*it1);
				}

				i++;
			}
		} else{
			for(it1=T1.begin(); it1 != T1.end(); it1++) {
				ax.push_back(*it1);
			}
			ay.push_back(1);
		}

		if(poz2 != 0) {
			for(it1=T2.begin(), i = 1 ; it1 != T2.end(); it1++) {
				if(i <= poz2) {
					bx.push_back(*it1);
				}
				if(i > poz2) {
					by.push_back(*it1);
				}

				i++;
			}
		} else{
			for(it1=T2.begin(); it1 != T2.end(); it1++) {
				bx.push_back(*it1);
			}
			by.push_back(1);
		}
		poz1 = poz2 = 0;
	
		ax = mnozenie(ax, by);
		bx = mnozenie(bx, ay);

		//dodajemy mianownik
		ax = dodawanie(ax, bx);
		//wynik.splice(wynik.begin(),ax);
		
		//drukuj(wynik);
		//dzielnik
		by = mnozenie(by, ay);
		//drukuj(by);
		

		list <int> gcd;
		//cout<<"gcd: ";
		if(porownanie(ax, by) == '<') {
			 gcd = (GCD(by, ax));	
		} else {
			 gcd = (GCD(ax, by));			
		}
		/*
		drukuj(gcd);
		cout <<endl;

		//skracamy
		ax = dzielenie(ax, gcd);
		by = dzielenie(by, gcd); 

		cout<<"mianownik:";
		drukuj(ax);
		cout<<endl;

		cout<<"dzielnik:";
		drukuj(by);
		cout<<endl;
		*/

		//skracamy
		ax = dzielenie(ax, gcd);
		by = dzielenie(by, gcd); 

				pozw = ax.size();

		wynik.splice(wynik.end(), ax);
		wynik.splice(wynik.end(), by);

		return wynik;
		
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

	if(znak1==true && znak2==false) {
		znak_wyniku= true;
	}
	if(znak1==false && znak2==true) {
		znak_wyniku= true;
	}
	if(znak1 == true && znak2 == true) {
		znak_wyniku = false;
	}
	/*
	cout<< "znak 1: " <<znak1<<endl;
	cout<< "znak 2: " <<znak2<<endl;
	cout<< "znak w: " <<znak_wyniku<<endl;
	*/
	znak1 = znak2 = false;
	
	
	//liczby wymierne
	if(poz1!=0 || poz2!=0) {
		//oba maja znak
		list<int> ax, ay, bx, by;
		int i = 0;

		if(poz1 !=0) {
			for(it1=T1.begin(), i = 1 ; it1 != T1.end(); it1++) {
				if(i <= poz1) {
					ax.push_back(*it1);
				}
				if(i > poz1) {
					ay.push_back(*it1);
				}

				i++;
			}
		} else{
			for(it1=T1.begin(); it1 != T1.end(); it1++) {
				ax.push_back(*it1);
			}
			ay.push_back(1);
		}

		if(poz2 != 0) {
			for(it1=T2.begin(), i = 1 ; it1 != T2.end(); it1++) {
				if(i <= poz2) {
					bx.push_back(*it1);
				}
				if(i > poz2) {
					by.push_back(*it1);
				}

				i++;
			}
		} else{
			for(it1=T2.begin(); it1 != T2.end(); it1++) {
				bx.push_back(*it1);
			}
			by.push_back(1);
		}
		poz1 = poz2 = 0;

		ax = mnozenie(ax, bx);
		//drukuj(ax);
		ay = mnozenie(ay, by);
		//drukuj(ay);

		//cout<<"gcd: ";
		list <int> gcd = (GCD(ax, ay));	
		
		//drukuj(gcd);
		//cout <<endl;

		ax = dzielenie(ax, gcd); 
		ay = dzielenie(ay, gcd);

		pozw = ax.size();

		//ax.merge(ax);
		it1 = ax.end();
		ax.splice(it1, ay);

		return ax;

		//return dzielenie(ax, ay);

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
	
	for(list <list <int> >::iterator iter = wiersze.begin(); iter != wiersze.end(); iter++) {	
		pusty = dodawanie(pusty, *iter);		
						
	}
	
	wiersze.clear();
	return pusty;
}

list <int> odejmowanie(list <int> T1, list <int> T2) { 
	int x=0, carry=0;
	list <int> wynik;
	list<int>::reverse_iterator tip;
	
	if(!znak1 && znak2) {
		znak2 = false;
		znak1 = false;
		return dodawanie(T1,T2);
	
	}
	
	//pierwszy ujemny, drugi dodatni
	if(znak1 && !znak2) {
		znak1 = znak2= false;
		
		znak_wyniku = true;
		return dodawanie(T1, T2);
	}
	
	//oba ujemne
	if(znak1 && znak2) {
		//if(porownanie(T1, T2) == '<') {
			znak2 =  false;
			return dodawanie(T1,T2);
		//}
	
	}
	
	//szybkie sprawdzenie
	if(porownanie(T1,T2) == '<') {
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
	list<int> i;
	list <int> offset;
	list <int> jeden;

	if(znak1== true && znak2 == false) { 
		znak_wyniku = true;
		//znak1 = znak2 = false;
	}
	if(znak1== false && znak2 == true) { 
		znak_wyniku = true;
		znak1 = znak2 = false;
	}	
	if(znak1== true && znak2 == true) { 
		znak_wyniku = false;
		znak1 = znak2 = false;
	}
	
	//znak1 = znak2 = false;
	
	
	
	i.push_back(1);
	offset.push_back(0);
	jeden.push_back(1);
	wynik.push_back(0);

	while(1) {
					
			//* l + T2 <= T1 && wynik * T2 <= T1
			if((porownanie(dodawanie(offset, T2), T1) == '<' || (porownanie(dodawanie(offset, T2), T1) == '=')) && 
			(porownanie(mnozenie(wynik, T2), T1) == '<' || porownanie(mnozenie(wynik, T2), T1) == '=' )) {

				// ((i+i) * T2) + l > T1
				if(porownanie(dodawanie(mnozenie(dodawanie(i, i), T2), offset), T1) == '>'  ) {
					// ((i*T2) + l)
					offset = dodawanie(mnozenie(i, T2), offset);
						
					wynik = dodawanie(wynik, i); 
					i = jeden;

					} else {
						i = dodawanie(i, i);
					}

				} else {
					break;
				}
	
		
	}
	if(znak_wyniku==true) {
		wynik =dodawanie(wynik, jeden);
	}
	
	if(wynik.front() == 0 && wynik.size() == 1 && znak_wyniku==true) {
		znak_wyniku=false;
	}
		
	return wynik;
}	

list <int> modulo(list <int> T1, list <int> T2) {
	list <int> wynik;
	bool x;
	if(znak1==true && znak2==false) {
		x = false;
			
		wynik = odejmowanie(T1, mnozenie(T2, dzielenie(T1, T2)) );	
		znak_wyniku = x;
		return wynik;
	
	} else {
	
	wynik = odejmowanie(T1, mnozenie(T2, dzielenie(T1, T2)) );	
	//cout<<"znak "<< znak_wyniku<<endl;

	
	return wynik;
	}
}

list<int> GCD(list <int> a, list <int> b ) {
	list <int> zero, t;
	zero.push_back(0);
	
	if(porownanie(a, b) == '<') {
		return GCD(b,a);
	}
	/*
	if(porownanie(b, zero) == '=') {
		return a;
	}

	return GCD(b, modulo(a,b));
	*/
	while(porownanie(b, zero) != '=') {
		t = b;
		b = modulo(a, b);
		a = t;
	
	}
	return a;
}

list <int> min(list <list <int> > x) {
	list <int> m;
	m.push_back(0);
	list <list <int> >::iterator iter = x.begin();

	m = *iter;

	for(; iter != x.end(); iter++) {
		if(porownanie(m, *iter) == '>') {
			m = *iter;
		}
	}

	return m;
}

list <int> GCD2(list <list<int> > x) {
	list <int> m;
	
	list <list <int> >::iterator iter = x.begin();

	//usuwanie zer
	while(iter != x.end() ) {
		if(iter->size() == 1 && *iter->begin() == 0) {
			//cout<< "mam dziada\n";
			x.erase(iter++);
		} else {
			++iter;
		}
	}

	iter = x.begin();
	
	do {
		m = min(x);
		
		for(iter = x.begin(); iter != x.end(); iter++) {
			*iter = modulo(*iter, m);
		}
		iter = x.begin();

		while(iter != x.end() ) {
			if(iter->size() == 1 && *iter->begin() == 0) {
				//cout<< "mam dziada\n";
				x.erase(iter++);
			} else {
				++iter;
			}
		}
		x.push_back(m);
	} while(x.size() >= 2);
	
	//cout<<"tutaj\n";
	
	
	return m;
}

list <int> prze_w_p(list<int> x) {
	bool carry = false;
	it1 = x.begin();

	while(it1 != x.end()) {
		if(carry)
			*it1 +=256;

		carry=false;
		if((*it1 & 1) == 1) {
			carry = true;
		}
		
		*it1 = *it1 >> 1;


		it1++;
	}

	if(x.front() == 0 && x.size() != 1) 
		x.pop_front();

	return x;
}

list <int> prze_w_l(list <int> x) {
	bool carry = false;

	rit1 = x.rbegin();
	while(rit1 != x.rend()) {
		*rit1 = *rit1 << 1;

		if(carry)
			*rit1 +=1;
		carry = false;

		if(*rit1 > 256) {
			//x.push_front(*rit1/256);
			*rit1 = *rit1 % 256;
			*rit1 = *rit1 & 255;
			carry = true;
		}
		//cout <<hex<<*rit1 << " ";

		rit1++;
	}
	if(carry) {
		x.push_front(1);
	}


	return x;
}

list <int> Stein(list <int> u, list <int> v) {
	list <int> zero, dwa;
	zero.push_back(0);
	dwa.push_back(2);
	
	cout<<"U: ";
	drukuj(u);

	cout<<"V: ";
	drukuj(v);
	cout<<endl;
	

	if(porownanie(u, v) == '=') 
		return u;
	if(porownanie(u, zero) =='=')
		return v;
	if(porownanie(v, zero) =='=') 
		return u;

	//jezeli u jest parzyste to...
	if(porownanie(modulo(u, dwa), zero) == '=') {
		//cout<<"ha!\n";
		if(!(porownanie(modulo(v, dwa), zero) == '=')){
			return Stein(prze_w_p(u), v);
		} else {
			return prze_w_p( Stein(prze_w_p(u), prze_w_p(v)));
		}	
	}
	if(porownanie(modulo(v, dwa), zero) == '=') {
		return Stein(u, prze_w_p(v));
	}


	if(porownanie(u,v) == '>') {
		return Stein(prze_w_p(odejmowanie(u,v)), v);
	}
	
	return Stein(prze_w_p(odejmowanie(v,u)), u);
	

	//return wynik;
}

//brzydki kawa³ kodu
void newtest() {
	list <list <int> > x;
	list <int> a, b, c;
	int j;

	srand(time(NULL));
		
	for(int i=0; i < 10; i++) {
		
		for(j=0; j < rand()%2+1; j++) {
			a.push_back(rand() % 255); 
		}
		
		for(j=0; j < rand()%2+1; j++) {
			b.push_back(rand() % 255); 
		}

		for(j=0; j < rand()%2+1; j++) {
			c.push_back(rand() % 255); 
		}

		x.push_back(a);
		x.push_back(b);
		x.push_back(c);

		//test!
		drukuj(a);
		drukuj(b);
		drukuj(c);
		if(porownanie(GCD(GCD(a,b),c), GCD2(x)) == '=') {
			cout<<"wynik = ";
			drukuj(GCD2(x));
			cout<< "Ok\n";
		} else{ 
			cout<<"OMG, error\n";
		}
		
		//drukuj(GCD(GCD(a,b),c));
		//drukuj(GCD2(x));
		
		cout<< "\n";
		
		znak_wyniku=false;
		x.clear();
		a.clear(); b.clear(); c.clear();
	}

	cout<<"Koniec Testu....\n";

}

int main(int argc, char **argv) {
	//newtest();
	char operacja;
		cin >> liczba1 >> operacja >> liczba2;
		zamiana();
		
		switch (operacja) {
			case '+': drukuj(dodawanie(L1, L2)); break;
		
			case '*': drukuj(mnozenie(L1,L2)); break;

			case '-': drukuj(odejmowanie(L1, L2)); break;

			case '/': drukuj(dzielenie(L1, L2)); break;

			case '%': drukuj(modulo(L1, L2)); break;

			case '?': cout << porownanie(L1,L2)<<endl; break;

			case 'g': drukuj(GCD(L1, L2)); break;

			case 's': drukuj(Stein(L1,L2)); break;

			case '>': drukuj(prze_w_p(L1)); break;

			case '<': drukuj(prze_w_l(L1)); break;

			case 't': for(int i=0; i<5; i++) 
						{newtest();} break;
			
			default:
				break;
		}

		L1.clear();
		L2.clear();

	return 0;
}
