#pragma once
#include "Column.h"
class ColumnString:public Column
{
private:
	list<string>* strings;
public:
	ColumnString(): Column() {
		strings = new list<string>();
	}
	~ColumnString() {
		delete strings;
	}
	void Add(string elem) override {
		strings->push_back(elem);
	}
	void AddStart(string elem) override {
		strings->push_front(elem);
	}
	void AddPosition(string elem, int pos) override {

	}
	void Remove(string elem) override {

	}
	void RemoveStart(string elem) override {

	}
	void RemovePosition(string elem, int pos) override {

	}
	void Modify(string elem, int pos) override {

	}
	void Print() override{
		for (auto c : *strings) {
			cout << c<<" ";
		}
	}
};

