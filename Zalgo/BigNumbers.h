#ifndef BIGNUMBERS_H
#define BIGNUMBERS_H

#include <iostream>
#include <list>
#include <string>

using namespace std;

//globalne
list<int> L1, L2; //, wynik;
list<int>::iterator it1, it2;
list<int>::reverse_iterator rit1, rit2;

string liczba1, liczba2;
bool znak = false;

int hex2dec(char);
void drukuj(list<int>);
void zamiana();
char porownanie(list<int>, list<int>);
list <int> dodawanie(list <int>, list <int>);
list <int> mnozenie(list <int>, list <int>);
list <int> odejmowanie(list <int>, list <int>);

#endif