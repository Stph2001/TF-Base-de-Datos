#pragma once
#include "Column.h"
class ColumnDouble:public Column
{
private:
	list<double>* doubles;
public:
	ColumnDouble() {
		doubles = new list<double>();
	}
	~ColumnDouble() {
		delete doubles;
	}
	void Add(double elem) override {
		doubles->push_back(elem);
	}
	void AddStart(double elem) override {
		doubles->push_front(elem);
	}
	void AddPosition(double elem, int pos) override {

	}
	void Remove(double elem) override {

	}
	void RemoveStart(double elem) override {

	}
	void RemovePosition(double elem, int pos) override {

	}
	void Modify(double elem, int pos) override {

	}
	void Print() override {
		for (auto c : *doubles) {
			cout << c << " ";
		}
	}
};

