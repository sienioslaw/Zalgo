#include <iostream>
#include <list>
#include <string>
#include <time.h>


#define BAZA 256
using namespace std;

//globalne
list<int> L1, L2; //, wynik;
list<int>::iterator it1, it2;
list<int>::reverse_iterator rit1, rit2;
string liczba1, liczba2;

list <int> odejmowanie(list <int> T1, list <int> T2);
list <int> dzielenie(list <int> T1, list <int> T2);
list <int> mnozenie(list <int> T1, list <int> T2);
list <int> GCD(list <int> T1, list <int> T2);
