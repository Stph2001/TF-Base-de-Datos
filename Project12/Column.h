#pragma once
#include <list>
#include <string>
#include <iostream>
#include "AvlTree.h"
using namespace std;

template<typename T>
class Column
{
private:
	string ColumnName;
	list<T>* datas;
	AvlTree<T>* avlTree;

public:
	Column() {
		datas = new list<T>();
		avlTree = nullptr;
	}
	~Column() {
		delete datas;

	}
	void Add(T elem) {
		datas->push_back(elem);
		if (avlTree != nullptr) avlTree->Add(elem);
	}
	void AddStart(T elem) {
		datas->push_front(elem);
	}
	void AddPosition(T elem, int pos) {

	}
	void Remove(char elem) {

	}
	void RemoveStart(char elem) {

	}
	void RemovePosition(char elem, int pos) {

	}
	void Modify(char elem, int pos) {

	}
	void Print() {
		for (auto c : *datas)
			cout << c << "\n";
	}
	int Length() {
		return datas->size();
	}
	void Index(function<double(T)> c) {
		generateTree(c);
		for (T c : *datas)
			avlTree->Add(c);
	}
	T Search(T elem) {
		if (avlTree != nullptr) return avlTree->Search(elem);
		return 0;
	}
	list<T>* Equals(T elem) {
		if (avlTree != nullptr) return avlTree->Equals(elem);
		return new list<T>();
	}
	list<T>* GreaterThan(T elem) {
		if (avlTree != nullptr) return avlTree->GreaterThan(elem);
		return new list<T>();
	}
	list<T>* LessThan(T elem) {
		if (avlTree != nullptr) return avlTree->LessThan(elem);
		return new list<T>();
	}
	void generateTree(function<double(T)> c) {
		if (avlTree == nullptr)
			avlTree = new AvlTree<T>(c);
	}
	void deleteTree() {
		if (avlTree == nullptr) return;
		if (avlTree->Length() <= 0) return;
		avlTree->Clear();
		delete avlTree;
		avlTree = nullptr;
	}
};

