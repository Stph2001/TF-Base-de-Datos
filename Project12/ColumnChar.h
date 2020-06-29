#pragma once
#include "Column.h"
class ColumnChar : public Column
{
private:
	list<char>* chars;

public:
	ColumnChar() : Column() {
		chars = new list<char>();
	}
	~ColumnChar() {
		delete chars;
	}
	void Add(char elem) override {
		chars->push_back(elem);
	}
	void AddStart(char elem) override {
		chars->push_front(elem);
	}
	void AddPosition(char elem, int pos) override {

	}
	void Remove(char elem) override {

	}
	void RemoveStart(char elem) override {

	}
	void RemovePosition(char elem, int pos) override {

	}
	void Modify(char elem, int pos) override {

	}
	void Print() override{
		for (auto c : *chars) {
			cout << c<<" ";
		}
	}
};

