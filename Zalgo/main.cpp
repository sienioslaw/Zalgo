#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(int argc, char **argv) {

	list<char> lista;
	list<char>::iterator it;
	string liczba;

	cout << "Podaj liczbe: ";
	cin >> liczba;

	for(int i=0; i< liczba.length(); i++) {
		lista.push_back(liczba[i]);
	}

	for(it=lista.begin(); it != lista.end(); it++) {
		cout << *it;
	}



	system("pause");
	return 0;
}