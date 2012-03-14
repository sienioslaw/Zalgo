#ifndef BIGNUMBERS_H
#define BIGNUMBERS_H

#define BAZA 256
#include <iostream>
#include <list>
#include <string>

using namespace std;

//globalne
extern list<int> L1, L2; //, wynik;
extern list<int>::iterator it1, it2;
extern list<int>::reverse_iterator rit1, rit2;

extern string liczba1, liczba2;
extern bool znak;

int hex2dec(char);
void drukuj(list<int>);
void zamiana();
char porownanie(list<int>, list<int>);
list <int> dodawanie(list <int>, list <int>);
list <int> mnozenie(list <int>, list <int>);
list <int> odejmowanie(list <int>, list <int>);

#endif