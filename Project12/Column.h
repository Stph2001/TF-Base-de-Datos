#pragma once
#include <list>
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
		if (avlTree != nullptr) avlTree->Add(elem, datas->size() - 1);
	}
	void Remove(T elem){
		if (avlTree != nullptr)avlTree->Remove(elem);
	}
	void AddStart(T elem) {
		datas->push_front(elem);
	}
	void AddPosition(T elem, int pos) {

	}
	void RemoveStart(T elem) {

	}
	void RemovePosition(T elem, int pos) {

	}
	void Modify(T elem, int pos) {

	}
	void Print() {
		for (auto c : *datas)
			cout << "\n" << c << "|";
	}
	int Length() {
		return datas->size();
	}
	void Index(function<int(T, T)> c, function<bool(string, T)> h, function<bool(string, T)> s, function<bool(string, T)> e) {
		generateTree(c,h, s,e);
		for (T p : *datas)
			avlTree->Add(p, datas->size() - 1);
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
	list<T>* Contains(string searcher) {
		if (avlTree != nullptr) return avlTree->Contains(searcher);
		return new list<T>();
	}
	list<T>* NotContains(string searcher) {
		if (avlTree != nullptr) return avlTree->NotContains(searcher);
		return new list<T>();
	}
	list<T>* StartWith(string searcher) {
		if (avlTree != nullptr) return avlTree->StartWith(searcher);
		return new list<T>();
	}
	list<T>* EndWith(string searcher) {
		if (avlTree != nullptr) return avlTree->EndWith(searcher);
		return new list<T>();
	}
	list<T>* InOrder() {
		if (avlTree != nullptr) return avlTree->InOrder();
		return new list<T>();
	}
	list<T>* InReverse() {
		if (avlTree != nullptr) return avlTree->InReverse();
		return new list<T>();
	}
	void generateTree(function<int(T, T)> c, function<bool(string, T)> h, function<bool(string, T)> s, function<bool(string, T)> e) {
		if (avlTree == nullptr)
			avlTree = new AvlTree<T>(c, h, s, e);
	}
	void deleteTree() {
		if (avlTree == nullptr) return;
		if (avlTree->Length() <= 0) return;
		avlTree->Clear();
		delete avlTree;
		avlTree = nullptr;
	}
};

