#pragma once
#include "ColumnChar.h"
#include "ColumnString.h"
#include "ColumnDouble.h"

class ArrayColumn
{
private:
	Column** columns;
	int nColumns;

public:
	ArrayColumn(){
		nColumns = 0;
	}
	~ArrayColumn(){

	}
	void AddColumn(string type){
		Column** aux = new Column * [nColumns + 1];
		if (nColumns>0)
			for (int i = 0; i < nColumns; i++)
				aux[i] = columns[i];
		
		if (type == "letters"){
			aux[nColumns] = new ColumnChar();
		}
		else if (type == "words"){
			aux[nColumns] = new ColumnString();
		}
		else {
			aux[nColumns] = new ColumnDouble();
		}
		nColumns++;
		columns = aux;
	}
	void PrintColumn(int pos){
		columns[pos]->Print();
	}
	Column *getColumn(int pos){
		return columns[pos];
	}
	void AddDouble(double a, int i){
		columns[i]->Add(a);
	}
	void AddString(string a, int i){
		columns[i]->Add(a);
	}
	void AddChar(char a, int i){
		columns[i]->Add(a);
	}
};

