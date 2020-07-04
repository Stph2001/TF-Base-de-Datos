#pragma once
#include "Column.h"
#include <map>
#include <vector>
template<typename T>
class ArrayColumn 
{
private:
	map<string, Column<T>*> columns;

public:
	ArrayColumn(){
	}
	~ArrayColumn(){
		if (columns != nullptr) {
			columns.erase();
		}
		deleteTree();
		delete os;
	}
	void AddColumn(string nameColumn){
		columns[nameColumn] = new Column<T>();
		//columns->insert(nameColumn, new Column<T>());
	}
	void Remove(T elem, string nameColumn){
		return columns[nameColumn]->Remove(elem);
	}
	int Search(T elem, string nameColumn){
		return columns[nameColumn]->Search(elem);
	}
	list<int>* GreaterThan(T elem, string nameColumn){
		return columns[nameColumn]->GreaterThan(elem);
	}
	list<int>* LessThan(T elem, string nameColumn){
		return columns[nameColumn]->LessThan(elem);
	}
	list<int>* Equals(T elem, string nameColumn) {
		return columns[nameColumn]->Equals(elem);
	}
	list<int>* Contains(string searcher, string nameColumn) {
		return columns[nameColumn]->Contains(searcher);
	}
	list<int>* NotContains(string searcher, string nameColumn){
		return columns[nameColumn]->NotContains(searcher);
	}
	list<int>* StartWith(string searcher, string nameColumn){
		return columns[nameColumn]->StartWith(searcher);
	}
	list<int>* EndWith(string searcher, string nameColumn) {
		return columns[nameColumn]->EndWith(searcher);
	}
	list<int>* InOrder(string nameColumn) {
		return columns[nameColumn]->InOrder();
	}
	list<int>* InReverse(string nameColumn) {
		return columns[nameColumn]->InReverse();
	}
	void IndexColumn(string nameColumn, function<int(T, T)> c, function<bool(string, T)> h, function<bool(string, T)> s, function<bool(string, T)> e){
		
		columns[nameColumn]->Index(c,h,s,e);
	}
	void RemoveIndexColumn(string nameColumn){
		columns[nameColumn]->deleteTree();
	}
	void PrintColumn(string nameColumn){
		columns[nameColumn]->Print();
	}
	Column<T> *getColumn(string nameColumn){
		return columns[nameColumn];
	}
	void AddToColumn(T elem, string nameColumn){
		columns[nameColumn]->Add(elem);
	}
	void SaveDataColumn(Archive* os) {
		for (map<string, Column<T>*>::iterator it = columns.begin(); it != columns.end(); it++) {
			if (it->second != nullptr)
				it->second->SaveData(os);
		}
	}
};

