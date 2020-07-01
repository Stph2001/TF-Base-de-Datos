#pragma once
#include "Column.h"

template<typename T>
class ArrayColumn 
{
private:
	Column<T>** columns;
	int nColumns;

public:
	ArrayColumn(){
		nColumns = 0;
	}
	~ArrayColumn(){
		if (nColumns > 0) {
			for (int i = 0; i < nColumns; i++)
				delete columns[i];
			delete columns;
			nColumns = 0;
		}
		deleteTree();
	}
	void AddColumn(){
		Column<T>** aux = new Column<T> * [nColumns + 1];
		if (nColumns>0)
			for (int i = 0; i < nColumns; i++)
				aux[i] = columns[i];
		aux[nColumns] = new Column<T>();
		nColumns++;
		columns = aux;
	}
	T Search(T elem, int pos){
		return columns[pos]->Search(elem);
	}
	list<T>* GreaterThan(T elem, int pos){
		return columns[pos]->GreaterThan(elem);
	}
	list<T>* LessThan(T elem, int pos){
		return columns[pos]->LessThan(elem);
	}
	list<T>* Equals(T elem, int pos) {
		return columns[pos]->Equals(elem);
	}
	void IndexColumn(int pos, function<double(T)> c){
		columns[pos]->Index(c);
	}
	void RemoveIndexColumn(int pos){
		columns[pos]->deleteTree();
	}
	void PrintColumn(int pos){
		columns[pos]->Print();
	}
	Column<T> *getColumn(int pos){
		return columns[pos];
	}
	void AddToColumn(T elem, int pos){
		columns[pos]->Add(elem);
	}
	int Length(){
		return nColumns;
	}
};

