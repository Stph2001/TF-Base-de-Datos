#pragma once
#include <list>
#include <string>
#include <iostream>
using namespace std;

class Column
{
protected:
	string ColumnName;

public:
	Column(){
		
	}
	~Column(){

	}
	virtual void Add(char elem) {}
	virtual void Add(string elem) {}
	virtual void Add(double elem) {}

	virtual void AddStart(char elem) {}
	virtual void AddStart(string elem) {}
	virtual void AddStart(double elem) {}

	virtual void AddPosition(char elem, int pos) {}
	virtual void AddPosition(string elem, int pos) {}
	virtual void AddPosition(double elem, int pos) {}

	virtual void Remove(char elem) {}
	virtual void Remove(string elem) {}
	virtual void Remove(double elem) {}

	virtual void RemoveStart(char elem) {}
	virtual void RemoveStart(string elem) {}
	virtual void RemoveStart(double elem) {}

	virtual void RemovePosition(char elem, int pos) {}
	virtual void RemovePosition(string elem, int pos) {}
	virtual void RemovePosition(double elem, int pos) {}

	virtual void Modify(char elem, int pos) {}
	virtual void Modify(string elem, int pos) {}
	virtual void Modify(double elem, int pos) {}

	virtual void Print(){}

	void setName(string name) {
		ColumnName = name;
	}
};

