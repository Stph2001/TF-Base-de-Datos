#pragma once
#include <iostream>
#include <conio.h>
#include <list>
using namespace std;

template<typename T>
int SearchAux(list<T>*elems, T elem){
	int cont = 0;
	for(auto s: *elems){
		if(s==elem){
			return cont;
		}
		cont++;
	}
	return -1;
}

template<typename T>
list<int>* EqualsAux(list<T>* elems, T elem){
	list<int>* auxList = new list<int>();
	for (auto s : *elems) {
		if (s == elem) {
			auxlist->push_back(s);
		}
	}
	return auxList;
}

template<typename T>
list<int>* GreatherThanAux(list<T>*elems,T elem){
	list<int>* auxList = new list<int>();
	for (auto s : *elems) {
		if (s > elem) {
			auxlist->push_back(s);
		}
	}
	return auxList;
}

template<typename T>
list<int>* LessThanAux(list<T>*elems,T elem){
	list<int>* auxList = new list<int>();
	for (auto s : *elems) {
		if (s < elem) {
			auxlist->push_back(s);
		}
	}
	return auxList;
}

template<typename T>
list<int>* ContainsAux(list<T>*elems,T elem){
	list<int>* auxList = new list<int>();
	string s;
	if(typeid(T)==typeid(char)) s.push_back(elem);
	if(typeid(T)==typeid(string)) s = elem;
	if(typeid(T)==typeid(double)){
		s= elem
	}
	return auxList;
}