#pragma once
#include <list>
#include <iostream>
#include "AvlTree.h"
#include "Archive.h"
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
			avlTree->Add(p);
	}
	int Search(T elem) {
		if (avlTree != nullptr) return avlTree->Search(elem);
		return 1;

	}
	list<int>* Equals(T elem) {
		if (avlTree != nullptr) return avlTree->Equals(elem);
		return new list<int>();
	}
	list<int>* GreaterThan(T elem) {
		if (avlTree != nullptr) return avlTree->GreaterThan(elem);
		return new list<int>();
	}
	list<int>* LessThan(T elem) {
		if (avlTree != nullptr) return avlTree->LessThan(elem);
		return new list<int>();
	}
	list<int>* Contains(string searcher) {
		if (avlTree != nullptr) return avlTree->Contains(searcher);
		return new list<int>();
	}
	list<int>* NotContains(string searcher) {
		if (avlTree != nullptr) return avlTree->NotContains(searcher);
		return new list<int>();
	}
	list<int>* StartWith(string searcher) {
		if (avlTree != nullptr) return avlTree->StartWith(searcher);
		return new list<int>();
	}
	list<int>* EndWith(string searcher) {
		if (avlTree != nullptr) return avlTree->EndWith(searcher);
		return new list<int>();
	}
	list<int>* InOrder() {
		if (avlTree != nullptr) return avlTree->InOrder();
		return new list<int>();
	}
	list<int>* InReverse() {
		if (avlTree != nullptr) return avlTree->InReverse();
		return new list<int>();
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
	void SaveData(Archive* os) {
		for (auto c : *datas) {
			os->Save(c);
		}
	}
};

