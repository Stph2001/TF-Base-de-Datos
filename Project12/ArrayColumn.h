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
		//columns = new map<string, Column<T>*>();
	}
	~ArrayColumn(){
		if (columns != nullptr) {
			columns.erase();
		}
		deleteTree();
	}
	void AddColumn(string nameColumn){
		columns[nameColumn] = new Column<T>();
		//columns->insert(nameColumn, new Column<T>());
	}
	void Remove(T elem, string nameColumn){
		return columns[nameColumn]->Remove(elem);
	}
	T Search(T elem, string nameColumn){
		return columns[nameColumn]->Search(elem);
	}
	list<T>* GreaterThan(T elem, string nameColumn){
		return columns[nameColumn]->GreaterThan(elem);
	}
	list<T>* LessThan(T elem, string nameColumn){
		return columns[nameColumn]->LessThan(elem);
	}
	list<T>* Equals(T elem, string nameColumn) {
		return columns[nameColumn]->Equals(elem);
	}
	list<T>* Contains(string searcher, string nameColumn) {
		return columns[nameColumn]->Contains(searcher);
	}
	list<T>* NotContains(string searcher, string nameColumn){
		return columns[nameColumn]->NotContains(searcher);
	}
	list<T>* StartWith(string searcher, string nameColumn){
		return columns[nameColumn]->StartWith(searcher);
	}
	list<T>* EndWith(string searcher, string nameColumn) {
		return columns[nameColumn]->EndWith(searcher);
	}
	list<T>* InOrder(string nameColumn) {
		return columns[nameColumn]->InOrder();
	}
	list<T>* InReverse(string nameColumn) {
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
};

